public class DNSTui {
    public Command nextCommand(String input) throws NoMatchException {
        String[] words = input.split(" ");
        if(words[0].equals("quit"))
            return new Quit();
        if(words.length > 1 && words[0].equals("ls")){
            if(words.length > 2 && words[1].equals("-a")){
                return new SearchByDomain(words[2],true);
            }else{
                return new SearchByDomain(words[1],false);
            }
        }else {
            try {
                AdresseIP a = AdresseIP.parseIP(input);
                return new SearchByIP(a);
            }catch (NoMatchException e) {
                try {
                    NomMachine m = NomMachine.parseNomMachine(input);
                    return new SearchByName(m);
                }catch(NoMatchException ee) {
                    throw new NoMatchException("ni une IP, ni un nom de machine, ni ls [-a] <domaine>");
                }
            }
        }
    }
    public void affiche(String out){
        System.out.println(out);
    }
}
