/**
 *  Třída PrikazNapoveda implementuje pro hru příkaz napoveda.
 *  Tato třída je součástí jednoduché textové hry.
 *  
 *@author     Jarmila Pavlickova, Tomáš Jakubčin (xjakt00)
 *@version    pro školní rok 2010/2011
 *  
 */
class PrikazNapoveda implements IPrikaz {

    private static final String NAZEV = "napoveda";
    private SeznamPrikazu platnePrikazy;
    private HerniPlan plan;

    /**
     *  Konstruktor třídy
     *  
     *  @param platnePrikazy seznam příkazů,
     *                       které je možné ve hře použít,
     *                       aby je nápověda mohla zobrazit uživateli. 
     */    
    public PrikazNapoveda(SeznamPrikazu platnePrikazy, HerniPlan plan) {
        this.platnePrikazy = platnePrikazy;
        this.plan = plan;
    }

    /**
     *  Vrací základní nápovědu po zadání příkazu "napoveda". Vypisuje se
     *  vcelku primitivní zpráva a seznam dostupných příkazů.
     *  
     *  @return napoveda ke hre
     */
    @Override
    public String proved(String... parametry) {
        Prostor mistnost = plan.getAktualniProstor();
        return "Musis pripravit skvelou party pro sveho kamarada. Jdi se porozhlednout \n"
        + "po okoli a neco nakoupit. Zbyva ti "+plan.getCas()+" minut. \n"
        + mistnost.dlouhyPopis()
        + "\nMuzes zadat tyto prikazy: "
        + platnePrikazy.vratNazvyPrikazu();
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
