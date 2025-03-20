public class Zad1 {
    public static void main(String[] args) {
        for (String number : args) {
            number = number.toUpperCase();
            try { System.out.println(number + " = " + ArabRzym.arab2rzym(Integer.parseInt(number))); }
            catch (NumberFormatException e) {
                try { System.out.println(number + " = " + ArabRzym.rzym2arab(number)); }
                catch (ArabRzym.ArabRzymException ee) { System.out.println(ee.getMessage()); } 
            }
            catch (ArabRzym.ArabRzymException e) { System.out.println(e.getMessage()); } 
        }
    }
}
