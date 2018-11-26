/*******************************************************************************
 * Příkaz 'vezmi' dovoluje hráči brát věci, které předtím položil. Nelze aplikovat
 * v obchodech.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazVezmi implements IPrikaz
{
    private static final String NAZEV = "vezmi";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /***************************************************************************
    /**
     *  Konstruktor třídy.
     *  
     *  @param batoh odkaz na hráčův batoh.
     *  @param plan  odkaz na herní plán.
     *  @param hra   odkaz na hru.
     */ 
    public PrikazVezmi(Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Zkontroluje parametry a další náležisoti - například jestli se hráč zrovna
     *  nenachází v obchodě, kde by si věc musel koupit. Pokud všechno dobře dopadne,
     *  získá hráč předmět a z prostoru tento předmět zmizí.
     */ 
    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Nevim, co mam vzit.";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        if (kdeJsme.getObchod() == true) {
            return "V obchode nemuzes veci jen tak brat, to by byla kradez! Pouzij prikaz kup.";
        }
        String nazevCoVzit = parametry [0];
        Vec vecicka = kdeJsme.vyberPolozenaVec(nazevCoVzit);
        if (vecicka == null)
            return "Tato vec v prostoru neni.";
        if (vecicka.isPrenosna() == false)
            return "Tuto vec nemuzes vzit, neni prenosna.";
        if (batoh.getPocetVeci()+1 > batoh.MAX_VECI)
            return "Tato vec se jiz do batohu nevejde.";
        if (batoh.getVaha()+vecicka.getVaha() > batoh.MAX_VAHA)
            return "Tato vec je moc tezka, vyprazdni nejdrive batoh.";
        if (plan.getCas()-1 > 0) {
            plan.setCas(1);
            vecicka.setVBatohu(1);
            batoh.setPocetVeci(1);
            batoh.setVaha(vecicka.getVaha());
            batoh.setVec(vecicka);
            kdeJsme.OdeberPolozeneVeci(vecicka);
            if (kdeJsme.getPocetPolozenaVec(vecicka) <= 0) {
                kdeJsme.removePolozenaVec(vecicka);
            }
            return "Vec '"+nazevCoVzit+"' se nyni nachazi ve tvem batohu.";
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
