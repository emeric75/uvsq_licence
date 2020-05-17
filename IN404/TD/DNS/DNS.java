import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.*;

public class DNS {
    private HashMap<AdresseIP,NomMachine> ip_machine;
    private HashMap<NomMachine,AdresseIP> machine_ip;
    private HashMap<String,ArrayList<DNSItem>> domain_map;
    public DNS(){
        Properties defaultProps = new Properties();
        try {
            FileInputStream in = new FileInputStream("defaultProperties.properties");
            defaultProps.load(in);
            in.close();
        }catch(IOException e) {
            e.printStackTrace();
            System.exit(1);
        }
        String fname = defaultProps.getProperty("filename","!");
        assert !(fname.equals("!")) : "DNS initialisation : no filename property found";
        File f = new File("db.txt");
        Scanner sc = null;
        try {
            sc = new Scanner(f);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.exit(1);
        }
        assert sc != null : "DNS : error initialising Scanner";
        ip_machine = new HashMap<>();
        machine_ip = new HashMap<>();
        domain_map = new HashMap<>();
        int line_count = 0;
        while(sc.hasNextLine()){
            try{
                String[] words = sc.nextLine().split(" ");
                NomMachine m = NomMachine.parseNomMachine(words[0]);
                AdresseIP a = AdresseIP.parseIP(words[1]);
                ip_machine.put(a,m);
                machine_ip.put(m,a);
                String dom = m.getDomain();
                //On ajoute à la liste associée à son domaine l'élément lu (si elle n'existe pas on la crée)
                if(!domain_map.containsKey(dom))
                    domain_map.put(dom,new ArrayList<>());
                domain_map.get(dom).add(new DNSItem(a,m));
            } catch (NoMatchException e) {
                System.out.print(fname + " : error parsing line " + line_count);
            }
            ++line_count;
        }
    }
    public NomMachine getItem(AdresseIP IP){
        return ip_machine.get(IP);
    }
    public AdresseIP getItem(NomMachine m){
        return machine_ip.get(m);
    }
    public ArrayList<DNSItem> getItems(String domain, boolean _a){
        ArrayList<DNSItem> out = domain_map.get(domain);
        if(out != null) {
            if (_a) {
                //on récupère l'IP du DNSItem, puis on trie par IPComparator
                out.sort(Comparator.comparing(i->i.getIP(),new IPComparator()));
            }else {
                out.sort(Comparator.comparing(i -> i.getName().toString()));
            }
        }
        return out;
    }
}
