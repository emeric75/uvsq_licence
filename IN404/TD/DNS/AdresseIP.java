import java.util.Arrays;

public class AdresseIP {
    private Integer[] IP;
    private AdresseIP(Integer[] IP){
        this.IP = IP;
    }
    public static AdresseIP parseIP(String s) throws NoMatchException {
        Integer[] IP = new Integer[4];
        if(s.matches("[0-9]+\\.[0-9]+\\.[0-9]+\\.[0-9]+")){
            String[] ss = s.split("\\.");
            for(int i = 0; i<4; i++){
                Integer to_add = Integer.parseInt(ss[i]);
                if(0 <= to_add && to_add <= 255) {
                    IP[i] = to_add;
                }else
                    throw new ArithmeticException("IP invalide : nombres entre 0 et 255");
            }
        }else{
            throw new NoMatchException("pas une adresse IP");
        }
        return new AdresseIP(IP);
    }
    @Override
    public String toString(){
        return IP[0].toString() + "." + IP[1].toString() + "." + IP[2].toString() + "." + IP[3].toString();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        AdresseIP adresseIP = (AdresseIP) o;
        return Arrays.equals(IP, adresseIP.IP);
    }

    @Override
    public int hashCode() {
        return Arrays.hashCode(IP);
    }
}
