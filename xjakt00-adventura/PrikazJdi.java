/**
 *  Třída PrikazJdi implementuje pro hru příkaz jdi.
 *  Tato třída je součástí jednoduché textové hry.
 *  
 *@author     Jarmila Pavlickova
 *@version    pro školní rok 2010/2011
 */
class PrikazJdi implements IPrikaz {
    private static final String NAZEV = "jdi";
    private HerniPlan plan;
    private Hra hra;

    /**
     *  Konstruktor třídy
     *  
     *  @param plan herní plán, ve kterém se bude ve hře "chodit".
     *  @param hra  hra.
     */    
    public PrikazJdi(HerniPlan plan, Hra hra) {
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Provádí příkaz "jdi". Zkouší se vyjít do zadané místnosti. Pokud místnost
     *  existuje, vstoupí se do nové místnosti. Pokud zadaná sousední
     *  místnosti (východ) není, vypíše se chybové hlášení.
     *
     *@param parametry - jako  parametr obsahuje jméno místnosti,
     *                         do které se má jít.
     *@return zpráva, kterou vypíše hra hráči
     */ 
    @Override
    public String proved(String... parametry) {
        if (parametry.length == 0) {
            // pokud chybí druhé slovo (sousední místnost), tak ....
            return "Kam mám jít? Musíš zadat jméno místnosti";
        }

        String smer = parametry[0];

        // zkoušíme přejít do sousední místnosti
        Prostor sousedniProstor = plan.getAktualniProstor().vratSousedniProstor(smer);

        if (sousedniProstor == null) {
            return "Tam se odsud jit neda!";
        }
        else {
            if (plan.getCas()-5 > 0) {
                plan.setAktualniProstor(sousedniProstor);
                plan.setCas(5); 
                return sousedniProstor.dlouhyPopis();
            }
            else {
                plan.konecHry();
                return "";
            }
        }
    }

    /**
     *  Metoda vrací název příkazu (slovo které používá hráč pro jeho vyvolání)
     *  
     *  @ return nazev prikazu
     */
    @Override
    public String getNazev() {
        return NAZEV;
    }

}
