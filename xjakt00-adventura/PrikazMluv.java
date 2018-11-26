/*******************************************************************************
 * Příkaz 'mluv' dovoluje hráči mluvis s osobami.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazMluv implements IPrikaz
{
    private static final String NAZEV = "mluv";
    private HerniPlan plan;
    private Hra hra;

    /**
     *  Konstruktor třídy.
     *  
     *  @param plan odkaz na herní plán.
     *  @param hra  odkaz na hru.
     */    
    public PrikazMluv(HerniPlan plan, Hra hra) {
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Zkontroluje parametry a další náležitosti, poté zavolá metodu, která zpracuje
     *  repliky dané osoby.
     */    
    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Nevim, s kym mam mluvit.";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        String jmenoSKymMluvit = parametry [0];
        Osoba osoba = kdeJsme.vyberOsobu(jmenoSKymMluvit);
        if (osoba == null)
            return "Tato osoba v prostoru neni.";
        if (plan.getCas()-3 > 0) {
            plan.setCas(3);
            if (osoba.getPred() == true) {
                return osoba.ZpracujVety(osoba.getMluvPred());
            }
            else {
                return osoba.ZpracujVety(osoba.getMluvPo());
            }
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
