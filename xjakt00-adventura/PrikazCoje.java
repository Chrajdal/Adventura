/*******************************************************************************
 * Tato třída impelmentuje pro hru příkaz 'coje'. Tento příkaz může mít
 * dva parametry - 'batoh' nebo 'tady'. V každém případě hráči ukáže věci
 * (a případně i osoby), které se v batohu/daném prostoru vyskytují.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/2011
 */
public class PrikazCoje implements IPrikaz {
    private static final String NAZEV = "coje";
    private HerniPlan plan;
    private Batoh batoh;
    private Hra hra;

    /***************************************************************************
     *  Konstruktor třídy 
     *  
     *  @param  hra     odkaz na hru.
     *  @param  batoh   odkaz na hráčův batoh.
     *  @param  plan    odkaz na herní plán.
     */
    public PrikazCoje (Batoh batoh, HerniPlan plan, Hra hra) {
        this.plan = plan;
        this.batoh = batoh;
        this.hra = hra;
    }

    /***************************************************************************
     * Tato metoda provádí daný příkaz.
     * Kontroluje, zda jsou správně zadáný parametry a v případě, že ne, informuje
     * o tom hráče. Jinak zavolá seznam, pomocí něhož vypíše vše, co se na daném místě
     * nachází.
     */
    public String proved (String... parametry) {
        if (parametry.length != 1) {
            return "Prikaz musi mit prave jeden parametr 'tady' ";
        }
        String kde = parametry[0];
        if (kde.equals("tady")) {
            if (plan.getCas()-1 > 0) {
                plan.setCas(1); 
                return plan.getAktualniProstor().seznamVeciAOsob();
            }
            else {
                plan.konecHry();
                return "";
            }
        }
        if (kde.equals("batoh")) {
            if (plan.getCas()-1 > 0) {
                plan.setCas(1);
                return batoh.seznamVeci();
            }
            else {
                plan.konecHry();
                return "";
            }
        }
        return "Prikaz musi mit tvar: 'coje tady' nebo 'coje batoh' ";
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