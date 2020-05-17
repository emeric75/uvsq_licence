import java.util.Comparator;

public class IPComparator implements Comparator<AdresseIP> {
    @Override
    public int compare(AdresseIP o1, AdresseIP o2) {
        Integer[] a1 = o1.getIP();
        Integer[] a2 = o2.getIP();
        for(int i = 0; i<4; i++){
            if(a1[i] < a2[i])
                return -1;
            else if(a1[i] > a2[i])
                return 1;
        }
        return 0;
    }
}
