/*******************************************************************************
 * Příkaz 'poloz' umožňuje hráči pokládat předměty. Pokud je však do obchodu, zmizí.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class PrikazPoloz implements IPrikaz
{
    private static final String NAZEV = "poloz";
    private Batoh batoh;
    private HerniPlan plan;
    private Hra hra;

    /**
     *  Konstruktor třídy.
     *  
     *  @param batoh odkaz na hráčův batoh.
     *  @param plan  odkaz na herní plán.
     *  @param hra   odkaz na hru.
     */ 
    public PrikazPoloz (Batoh batoh, HerniPlan plan, Hra hra) {
        this.batoh = batoh;
        this.plan = plan;
        this.hra = hra;
    }

    /**
     *  Zkontroluje parametry a další náležitosti, poté předmět vyndá z batohu
     *  a přenastaví vešekeré proměnné. V případě, že se nejedná o obchod, přidá
     *  také předmět do prostoru mezi tzv. položené předměty.
     */ 
    public String proved (String... parametry) {
        if (parametry.length == 0) {
            return "Nevim, co mam polozit.";
        }
        Prostor kdeJsme = plan.getAktualniProstor();
        String nazevCoPolozit = parametry [0];
        Vec vecicka = batoh.vyberVec(nazevCoPolozit);
        if (vecicka == null)
            return "Tato vec v batohu neni.";
        if (plan.getCas()-1 > 0) {
            plan.setCas(1);
            batoh.setPocetVeci(-1);
            batoh.setVaha(-vecicka.getVaha());
            if (kdeJsme.getObchod() == false) {
                kdeJsme.PridejPolozeneVeci(vecicka);
                vecicka.setVBatohu(-1);
                if (vecicka.getVBatohu() <= 0) {
                    batoh.removeVec(vecicka);
                }
                return "Vec '"+nazevCoPolozit+"' byla polozena a zustane na zemi.";
            }
            else {
                return "Vec '"+nazevCoPolozit+"' byla polozena, ovsem pracovnici obchodu ji"+
                " rychle uklidili, proto uz nebude nadale dostupna.";
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
