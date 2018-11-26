/*******************************************************************************
 * Pomocí příkazu 'vymen' může hráč vyměňovat předměty s jinými postavami.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazVymen implements IPrikaz
{
    private static final String NAZEV = "vymen";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /**
     *  Konstruktor třídy.
     *  
     *  @param batoh odkaz na hráčův batoh.
     *  @param plan  odkaz na herní plán.
     *  @param hra   odkaz na hru.
     */ 
    public PrikazVymen (Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Metoda zařídí parametrů (osoba, věc, kterou chceme dát a věc, kterou chceme dostat), poté
     *  provede výměnu.
     */ 
    public String proved (String... parametry) {
        Prostor kdeJsme = plan.getAktualniProstor();
        if (parametry.length == 0) {
            return "Nevim, s kym mam vymenovat.";
        }
        String jmenoKomuDat = parametry [0];
        String nazevCoDat;
        try {
            nazevCoDat = parametry [1];
        }
        catch (java.lang.ArrayIndexOutOfBoundsException e) {
            return "Nevim, co mam nabidnout - musis zadat vic parametru";
        }
        String nazevCoVzit;
        try {
            nazevCoVzit = parametry [2];
        }
        catch (java.lang.ArrayIndexOutOfBoundsException e) {
            return "Nevim, co mam chtit zpatky - musis zadat vic parametru";
        }
        Osoba osoba = kdeJsme.vyberOsobu(jmenoKomuDat);
        if (osoba == null) {
            return "Tato osoba v prostoru neni.";
        }
        Vec vecicka = batoh.vyberVec(nazevCoDat);
        if (vecicka == null) {
            return "Tuto vec nemas v batohu";
        }
        Vec vecicka2 = osoba.vyberVec(nazevCoVzit);
        if (vecicka2 == null) {
            return "Tuto vec nema osoba v batohu";
        }
        if (!(nazevCoDat.equals(osoba.getVecKterouChce())))
            return "Tuto vec osoba nechce.";
        if (osoba.getVecKterouChceMnozstvi() > vecicka.getVBatohu())
            return "Mas malo kusu dane veci.";
        if (plan.getCas()-5 > 0) {
            plan.setCas(5);
            batoh.setPocetVeci(-osoba.getVecKterouChceMnozstvi());
            batoh.setVaha(-(vecicka.getVaha()*osoba.getVecKterouChceMnozstvi()));
            vecicka.setVBatohu(-osoba.getVecKterouChceMnozstvi());
            osoba.setVec(vecicka);
            if (vecicka.getVBatohu() <= 0) {
                batoh.removeVec(vecicka);
            }
            batoh.setVec(vecicka2);
            batoh.setPocetVeci(1);
            batoh.setVaha(vecicka2.getVaha());
            vecicka2.setVBatohu(1);
            osoba.setPred(false);
            return "Dal jsi vec '"+nazevCoDat+"' osobe '"+osoba.getJmeno()+" a dostal vec '"+
            nazevCoVzit+"'.";
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
