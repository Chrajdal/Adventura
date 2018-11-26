/*******************************************************************************
 * Pomocí příkazu 'dej' může hráč předávat osobám určitě předměty.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazDej implements IPrikaz
{
    private static final String NAZEV = "dej";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /***************************************************************************
     *  Konstruktor třídy.
     *  
     *  @param batoh odkaz na hráčův batoh.
     *  @param plan  odkaz na herní plán.
     *  @param hra   odkaz na hru.
     */ 
    public PrikazDej(Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Zkontroluje parametry (musí být dva - osoba a věc, kterou chce hráč předat)
     *  a předá věc.
     */ 
    public String proved (String... parametry) {
        Prostor kdeJsme = plan.getAktualniProstor();
        if (parametry.length == 0) {
            return "Nevim, komu mam co dat.";
        }
        String jmenoKomuDat = parametry [0];
        String nazevCoDat;
        try {
            nazevCoDat = parametry [1];
        }
        catch (java.lang.ArrayIndexOutOfBoundsException e) {
            return "Nevim, co mam dat - musis zadat dva parametry";
        }
        Osoba osoba = kdeJsme.vyberOsobu(jmenoKomuDat);
        Vec vecicka = batoh.vyberVec(nazevCoDat);
        if (osoba == null) {
            return "Tato osoba v prostoru neni.";
        }
        if (vecicka == null) {
            return "Tuto vec nemas v batohu";
        }
        if (osoba.maVec(nazevCoDat) == true) {
            return "Osoba uz tuto vec ma a dalsi nejspis nepotrebuje.";
        }
        if (plan.getCas()-1 > 0) {
            plan.setCas(3);
            batoh.setPocetVeci(-1);
            batoh.setVaha(-vecicka.getVaha());
            vecicka.setVBatohu(-1);
            osoba.setVec(vecicka);
            if (vecicka.getVBatohu() <= 0) {
                batoh.removeVec(vecicka);
            }
            return "Dal jsi vec '"+nazevCoDat+"' osobe '"+osoba.getJmeno()+"'.";
        }
        else {
            plan.konecHry();
            return "";
        }
    }

    /**
     *  Metoda vrací název příkazu (slovo které používá hráč pro jeho vyvolání)
     *  
     *  @ return nazev prikazu
     */
    public String getNazev() {
        return NAZEV;
    }

}
