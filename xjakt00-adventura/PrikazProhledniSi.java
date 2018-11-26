/*******************************************************************************
 * Prikaz 'prohledniSi' dovoluje hráči zjistit více informací o věcech v obchodech,
 * například jeho hmotnost nebo cenu.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazProhledniSi implements IPrikaz
{
    private static final String NAZEV = "prohledniSi";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /***************************************************************************
     *  Konstruktor třídy.
     *  
     *  @param  hra     odkaz na hru.
     *  @param  batoh   odkaz na hráčův batoh.
     *  @param  plan    odkaz na herní plán.
     */
    public PrikazProhledniSi(Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /***************************************************************************
     *  Tato etoda provádí daný příkaz. Kontroluje, jestli byl zadán parametr a vypisuje
     *  informace o věcech.
     */

    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Nevim, co si mam prohlednout.";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        String nazevCoProhlednout = parametry [0];
        Vec vecicka = kdeJsme.vyberVec(nazevCoProhlednout);
        if (vecicka == null)
            return "Tato vec v prostoru neni.";
        if (plan.getCas()-1 > 0) {
            plan.setCas(1);
            return "Vec "+nazevCoProhlednout+" - "+vecicka.getPopis()+" stoji "
            +vecicka.getCena()+"Kc a vazi "+vecicka.getVaha()+"g.";
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
