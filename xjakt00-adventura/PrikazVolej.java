/*******************************************************************************
 * Příkaz 'volej' dovoluje hráči zvát ostatní osoby na party.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazVolej implements IPrikaz
{
    private static final String NAZEV = "volej";
    private HerniPlan plan;
    private Batoh batoh;
    private Prostor pryc;
    private Hra hra;

    /***************************************************************************
     *  Konstruktor třídy. Kromě plánu a batohu se zde také vytváří také prostor
     *  a v něm i několik osob - kamarádů.
     *  
     *  @param batoh odkaz na hráčův batoh.
     *  @param plan  odkaz na herní plán.
     *  @param hra   odkaz na hru.
     */ 
    public PrikazVolej(Batoh batoh, HerniPlan plan, Hra hra) {
        this.plan = plan;
        this.batoh = batoh;
        this.hra = hra;
        pryc = new Prostor ("pryc", "Prostor urceny pro kamarady z telefonu apod.", false);
        pryc.setOsoba (new Osoba ("Michal", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Roman", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Tomas", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Lubor", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Petr", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Erik", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Martin", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Bohous", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Josef", "kamarad", null, null, null, 0, false));
        pryc.setOsoba (new Osoba ("Karel", "kamarad", null, null, null, 0, false));
    }

    /**
     *  Metoda proveď musí zkontrolovat parametry a zjistit, jestli je možné
     *  se danému člověku dovolat. Poté změní jeho proměnnou 'pozvana' na true.
     */ 
    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Musis zadat komu volat. Pokud ani sam nevis, komu muzes zavolat, napis 'volej koho'.";
        }
        String jmenoSKymMluvit = parametry [0];
        if (jmenoSKymMluvit.equals("koho")) {
            return pryc.seznamVeciAOsob();
        }
        else {
            Prostor kdeJsme = plan.getAktualniProstor();
            Osoba osoba = pryc.vyberOsobu(jmenoSKymMluvit);
            if (osoba == null)
                return "Teto osobe nemuzes volat. Pokud ani sam nevis, komu muzes zavolat, napis 'volej koho'.";
            if (osoba.getPozvana() == true)
                return "Tato osoba je jiz pozvana.";
            if (batoh.vyberVec("mobil") == null) {
                if (!(kdeJsme.getNazev().equals("byt"))) {
                    return "Abys mohl volat, musis byt bud doma, anebo mit mobil.";
                }
            }
            if (plan.getCas()-10 > 0) {
                plan.setCas(10);
                osoba.setPozvana(true);
                plan.setLidiPozvanych(1);
                return "Osoba "+osoba.getJmeno()+" byla pozvana na party.";
            }
            else {
                plan.konecHry();
                return "";
            }
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
