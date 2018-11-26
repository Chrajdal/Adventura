/**
 *  Třída PrikazKonec implementuje pro hru příkaz hraj.
 *  Tato třída je součástí jednoduché textové hry.
 *  
 *@author     Tomáš Jakučbin (xjakt00)
 *@version    pro školní rok 2010/2011
 *  
 */

class PrikazHraj implements IPrikaz {
    private static final String NAZEV = "hraj";
    private Hra hra;
    private HerniPlan plan;

    /**
     *  Konstruktor třídy
     *  
     *  @param hra odkaz na hru, která má být příkazem hraj spustena. 
     *  @param plan odkaz na herní plán.
     */ 
    public PrikazHraj(Hra hra, HerniPlan plan) {
        this.hra = hra;
        this.plan = plan;
    }

    /**
     * V případě, že příkaz má jen jedno slovo "hraj" hra začíná.
     * 
     * @return zpráva, kterou vypíše hra hráči
     */

    @Override
    public String proved(String... parametry) {
        if (parametry.length > 0) {
            return "Hraj co? Nechapu, proc jsi zadal druhe slovo.";
        }
        else {
            if (hra.getZacatekHry() == false) {
                hra.setZacatekHry(true);
                hra.nastavPrikazy();
                return "*Crrrrrrrr* \n" +
                "*Crrrrrrrr* \n" +
                "Ty: 'Halo?' \n" +
                "Pavel: 'Cus, tady Pavel, ty mas prej dneska volnej byt?' \n" +
                "Ty: 'No, to mam, ale... Pockej, proc?' \n" +
                "Pavel: 'Super, hele, Roman ma narozky, bude to u tebe doma, priprav mu poradnou \n" +
                "party, darky koupime, bude to dneska vecer, v osm zaciname, dik, musim, mej se.' \n" +
                "Ty: 'Ne, pockej, Paja ma dneska taky narozky, musim bejt s ni' \n" +
                "Pavel: 'V pohode, je pozvana, bude tam, ahoj.' *klap* \n" +
                "Ty: 'Parada, takze mam pet hodin. A jeste musim koupit darek Paje a najit svuj ztraceny mobil. Tak do toho!' \n \n" +
                plan.getAktualniProstor().dlouhyPopis();
            }
            else {
                return "Hra uz davno bezi.";
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
