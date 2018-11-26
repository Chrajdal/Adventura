/*******************************************************************************
 * Příkaz vydělat slouží k vydělávání peněz. Je možná ho provádět pouze doma
 * za pomoci počítače.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/2011
 */
public class PrikazVydelat implements IPrikaz {
    private static final String NAZEV = "vydelat";
    private HerniPlan plan;
    private Batoh batoh;
    private Hra hra;

    /***************************************************************************
     * Konstruktor třídy 
     *  
     *  @param  hra     odkaz na hru.
     *  @param  batoh   odkaz na hráčův batoh.
     *  @param  plan    odkaz na herní plán.
     */
    public PrikazVydelat (Batoh batoh, HerniPlan plan, Hra hra) {
        this.plan = plan;
        this.batoh = batoh;
        this.hra = hra;
    }

    /***************************************************************************
     * Tato metoda provádí daný příkaz.
     * Kontroluje, aby neměl žádný parametr a aby byl hráč doma. Poté hráči sebere
     * určitý čas a dá nějaké peníze.
     */
    public String proved (String... parametry) {
        if (parametry.length != 0) {
            return "Prikaz se zadava bez parametru!";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        if (!(kdeJsme.getNazev().equals("byt"))) {
            return "Abys mohl vydelavat, musis byt bud doma, potrebujes k tomu pocitac.";
        }
        if (plan.getCas()-30 > 0) {
            plan.setCas(30);
            batoh.setPenize(-150);
            return "Odpracoval sis 30 minut a vydělal 150Kč.";
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