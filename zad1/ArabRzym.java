public class ArabRzym {
    private static String[] liczby_r = 
    { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

    private static int[] liczby_a =
    { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };


    public static int rzym2arab (String rzym) throws ArabRzymException {
        int arab = 0;
        String original = rzym;
        for (int i=12; i>-1; i--) {
            int c = 0;
            while (rzym.startsWith(liczby_r[i])) {
                if (++c > 3) { throw new ArabRzymException("Niepoprawny argument: " + original + " (złe ułożenie znaków / niedozwolone znaki)"); }
                arab = arab + liczby_a[i];
                rzym = rzym.substring(liczby_r[i].length());
            }
        }

        if (rzym.length() > 0) {throw new ArabRzymException("Niepoprawny argument: " + original + " (złe ułożenie znaków / niedozwolone znaki)");}
        return arab;
    }
    

    public static String arab2rzym (int arab) throws ArabRzymException {
        if (arab<1 || arab>3999) { throw new ArabRzymException("Niepoprawny argument: " + arab + " (liczba musi być z zakresu [1;3999])"); }

        String rzym = "";
        for (int i=12; i>-1; i--) {
            while (arab >= liczby_a[i]) {
                rzym = rzym + liczby_r[i];
                arab = arab - liczby_a[i];
            }
        }
        return rzym;
    }


    public static class ArabRzymException extends Exception {
        public ArabRzymException(String msg) { super(msg); }
    }
}
