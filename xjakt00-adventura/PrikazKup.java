/*******************************************************************************
 * Příkaz 'kup' umožňuje hráči nakupovat věci v obchodech.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazKup implements IPrikaz
{
    private static final String NAZEV = "kup";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /***************************************************************************
     *  Konstruktor třídy.
     *  
     *  @param  plan    herni plan.
     *  @param  batoh   odkaz na hráčův batoh.
     *  @param  hra     odkaz na hru
     */
    public PrikazKup(Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /***************************************************************************
     *  Nejdříve kontroluje, jestli je zadný parametr a pak všechny další náležitosti -
     *  např. jestli se vejde do batohu apod. V případě, že všechno dobře dopadne, přidá
     *  hráči koupený předmět do batohu a odebere mu peníze. Nedá se uplatnit na věci, které
     *  jsou položeny.
     */
    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Nevim, co mam koupit.";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        if (kdeJsme.getObchod() == false) {
            return "Nemuzes koupit vec, ktera neni v obchode. Pouzij prikaz vezmi.";
        }
        String nazevCoKoupit = parametry [0];
        Vec vecicka = kdeJsme.vyberVec(nazevCoKoupit);
        if (vecicka == null)
            return "Tato vec v prostoru neni.";
        if (vecicka.isPrenosna() == false)
            return "Tuto vec nemuzes koupit, neni prenosna.";
        if (batoh.getPocetVeci()+1 > batoh.MAX_VECI)
            return "Tato vec se jiz do batohu nevejde.";
        if (batoh.getVaha()+vecicka.getVaha() > batoh.MAX_VAHA)
            return "Tato vec je moc tezka, vyprazdni nejdrive batoh.";
        if (vecicka.getCena() > batoh.getPenize())
            return "Na tuto vec nemas dostatek penez.";
        if (plan.getCas()-1 > 0) {
            plan.setCas(1);
            vecicka.setVBatohu(1);
            batoh.setPocetVeci(1);
            batoh.setVaha(vecicka.getVaha());
            batoh.setPenize(vecicka.getCena());
            batoh.setVec(vecicka);
            return "Vec '"+nazevCoKoupit+"' byla koupena a nachazi se nyni ve tvem batohu.";
        }
        else {
            plan.konecHry();
            return "";
        }
    }

    /***************************************************************************
     *
     */
    public String getNazev() {
        return NAZEV;
    }
}
