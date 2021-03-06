/**
 *  Třída Hra - třída představující logiku adventury.
 * 
 *  Toto je hlavní třída  logiky aplikace.  Tato třída vytváří instanci třídy HerniPlan, která inicializuje mistnosti hry
 *  a vytváří seznam platných příkazů a instance tříd provádějící jednotlivé příkazy.
 *  Vypisuje uvítací a ukončovací text hry.
 *  Také vyhodnocuje jednotlivé příkazy zadané uživatelem.
 *
 *@author     Michael Kolling, Lubos Pavlicek, Jarmila Pavlickova
 *@version    pro školní rok 2010/2011
 */

public class Hra {
    private SeznamPrikazu platnePrikazy;    // obsahuje seznam přípustných příkazů
    private HerniPlan herniPlan;
    private Batoh batoh;
    private boolean konecHry = false;
    private boolean zacatekHry = false;

    /**
     *  Vytváří hru a inicializuje místnosti (prostřednictvím třídy HerniPlan) a část seznamu platných příkazů.
     */
    public Hra() {
        batoh = new Batoh(5, 10000);
        herniPlan = new HerniPlan();
        platnePrikazy = new SeznamPrikazu();
        platnePrikazy.vlozPrikaz(new PrikazHraj(this, herniPlan));
        platnePrikazy.vlozPrikaz(new PrikazKonec(this));
    }

    /**
     *  Vrátí úvodní zprávu pro hráče.
     */
    public String vratUvitani() {
        return "Vitejte!\n" +
        "Toto je nova adventura, ve ktere bude vasim cilem pripravit co nejlepsi \n" +
        "party pro kamarada. Ovsem nebudete mit prilis mnoho casu. Vice info o \n" +
        "pribehu si muzete precist v manualu. \n" +
        "Napiste 'napoveda', pokud si nevite rady, jak hrat dal nebo potrebujete \n" +
        "pripomenout prikazy. Hru spustite prikazem 'hraj' a ukoncite prikazem 'konec'. \n" +
        "Hodne stesti! \n";
    }

    /**
     *  Přidá zbytek příkazů.
     */
    public void nastavPrikazy() {
        platnePrikazy.vlozPrikaz(new PrikazNapoveda(platnePrikazy, herniPlan));
        platnePrikazy.vlozPrikaz(new PrikazJdi(herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazCoje(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazKup(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazPoloz(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazVezmi(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazMluv(herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazDej(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazVymen(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazVolej(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazVydelat(batoh, herniPlan, this));
        platnePrikazy.vlozPrikaz(new PrikazProhledniSi(batoh, herniPlan, this));
    }

    /**
     *  Vrátí závěrečnou zprávu pro hráče.
     */
    public String vratEpilog() {
        return "Dik, ze jste si zahrali. Ahoj.";
    }

    /** 
     * Vrací true, pokud hra skončila.
     */
    public boolean konecHry() {
        return konecHry;
    }

    /** 
     * Vrací true, pokud hra zacala.
     */
    public boolean getZacatekHry() {
        return zacatekHry;
    }

    /** 
     * Metoda k nastaveni hodnoty zacatekHry.
     */
    public void setZacatekHry(boolean zacatek) {
        zacatekHry = zacatek;
    }

    /**
     *  Metoda zpracuje řetězec uvedený jako parametr, rozdělí ho na slovo příkazu a další parametry.
     *  Pak otestuje zda příkaz je klíčovým slovem  např. jdi.
     *  Pokud ano spustí samotné provádění příkazu.
     *
     *@param  radek  text, který zadal uživatel jako příkaz do hry.
     *@return          vrací se řetězec, který se má vypsat na obrazovku
     */
    public String zpracujPrikaz(String radek) {
        String [] slova = radek.split("[ \t]+");
        String slovoPrikazu = slova[0];
        String []parametry = new String[slova.length-1];
        for(int i=0 ;i<parametry.length;i++){
            parametry[i]= slova[i+1];  	
        }
        String textKVypsani=" .... ";
        if (platnePrikazy.jePlatnyPrikaz(slovoPrikazu)) {
            IPrikaz prikaz = platnePrikazy.vratPrikaz(slovoPrikazu);
            textKVypsani = prikaz.proved(parametry);
        }
        else {
            textKVypsani="Nevim co tim myslis, tento prikaz neznam? ";
        }
        return textKVypsani;
    }

    /**
     *  Nastaví, že je konec hry, metodu využívá třída PrikazKonec,
     *  mohou ji použít i další implementace rozhraní Prikaz.
     *  
     *  @param  konecHry  hodnota false= konec hry, true = hra pokračuje
     */
    void setKonecHry(boolean konecHry) {
        this.konecHry = konecHry;
    }

    /**
     *  Metoda vrátí odkaz na herní plán, je využita hlavně v testech,
     *  kde se jejím prostřednictvím získává aktualní místnost hry.
     *  
     *  @return     odkaz na herní plán
     */
    public HerniPlan getHerniPlan(){
        return herniPlan;
    }

}

