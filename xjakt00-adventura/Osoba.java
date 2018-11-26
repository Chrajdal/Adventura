import java.util.*;

/*******************************************************************************
 * Třída osoba představuje veškeré postavy, které se ve hře nacházejí. Mají svůj
 * seznam věcí, několik replik (jako pole), někdy také věci, za které jsou ochotny
 * nabídnout nějaké své předměty. U každé navíc figuruje zvláštní proměrnná 'pozvana',
 * která určuje, jestli byla daná postava pozávana na oslavu nebo ne.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/2011
 */
public class Osoba
{
    private String jmeno;
    private String popis;
    private Set<Vec> veci;
    private String [] mluvPred;
    private String vecKterouChce;
    private int vecKterouChceMnozstvi;
    private boolean pred;
    private boolean pozvana;
    private String [] mluvPo;

    /***************************************************************************
     * Vytváří konkrétní osobu.
     * 
     * @param  jmeno                     jméno postavy.
     * @param  popis                     jednoduchý popis postavy.
     * @param  mluvPred                  pole vět, které bude postava říkat, dokud s ní hráč neprovede určitou akci.
     * @param  mluvPo                    pole vět, které bude psotava říkat, až s ní hráč provede určitou akci.
     * @param  vecKterouChce             věc, za kterou je postava ochotna vyměnit určitou svoji věc.
     * @param  vecKterouChceMnozstvi     množství věcí, které postava požaduje.
     * @param  pozvana                   určuje, jestli byla postava pozvána na party nebo ne.
     */
    public Osoba(String jmeno, String popis, String [] mluvPred, String [] mluvPo, String vecKterouChce, int vecKterouChceMnozstvi, boolean pozvana)
    {
        this.jmeno = jmeno;
        this.popis = popis;
        this.mluvPred = mluvPred;
        this.vecKterouChce = vecKterouChce;
        this.vecKterouChceMnozstvi = vecKterouChceMnozstvi;
        this.mluvPo = mluvPo;
        this.pozvana = pozvana;
        pred = true;
        veci = new HashSet<Vec>();
    }

    /***************************************************************************
     * Získá jméno.
     */
    public String getJmeno() {
        return jmeno;
    }

    /***************************************************************************
     * Získá popis.
     */
    public String getPopis() {
        return popis;
    }

    /***************************************************************************
     * Získá pole vět pro rozhovor před určitou akcí.
     */
    public String [] getMluvPred() {
        return mluvPred;
    }

    /***************************************************************************
     * Získá pole vět pro rozhovor po určité akci.
     */
    public String [] getMluvPo() {
        return mluvPo;
    }

    /***************************************************************************
     * Získá informaci o věci, kterou postava chce.
     */
    public String getVecKterouChce() {
        return vecKterouChce;
    }

    /***************************************************************************
     * Získá informaci o množství věcí, které postava chce.
     */
    public int getVecKterouChceMnozstvi() {
        return vecKterouChceMnozstvi;
    }

    /***************************************************************************
     * Zjistí, jestli už postava danou akci vykonala.
     */
    public boolean getPred() {
        return pred;
    }

    /***************************************************************************
     * Zjistí, jestli je postava pozvaná na party.
     */
    public boolean getPozvana() {
        return pozvana;
    }

    /***************************************************************************
     * Vrátí seznam věcí, které postava vlastní, je potřeba především k závěrečnému
     * vyhodnocení toho, jak moc byl hráč úspěšný u své dívky.
     */
    public Set<Vec> getVeci() {
        return veci;
    }

    /***************************************************************************
     * Metoda, která převezme pole replik osoby a náhodně vybere jednu z jejích vět,
     * kterou pak metoda pronese.
     * 
     * @return     vrátí náhodně vybranou repliku, která se pak hráči zobrazí.
     */
    public String ZpracujVety(String [] mluv) {
        Random rand = new Random();
        int mluvR = Math.abs(rand.nextInt()%mluv.length);
        String coRict = mluv [mluvR];
        return coRict;
    }

    /***************************************************************************
     * Přidá osobě věc do vlastnictví.
     */
    public void setVec(Vec v) {
        veci.add(v);
    }

    /***************************************************************************
     * Změní informaci o tom, jestli už byla provedena daná akce.
     */
    public void setPred(boolean pred) {
        this.pred = pred;
    }

    /***************************************************************************
     * Změní informaci o tom, jestli byla postava pozvaná.
     */
    public void setPozvana(boolean pozvana) {
        this.pozvana = pozvana;
    }

    /***************************************************************************
     * Metoda, která se používá ke zjišťování, jestli daná věc patří dané osobě
     * a následnému převádění názvu věci jako řetězce na konkrétní obejkt.
     * 
     * @param  jm     jméno věci, kterou chceme osobě vzít.
     * @return        věc jako obejkt, popř. null.
     */
    public Vec vyberVec(String jm) {
        for (Vec v : veci)
            if (v.getNazev().equals(jm)) {
                Vec vybranaVec = v;
                veci.remove(v);
                return vybranaVec;
        }
        return null;
    }

    /**
     * Metoda vrátí informaci o tom, jestli má daná osoba určitou věc.
     * 
     * @param  jm     jméno věci, o které chcem danou informaci zjistit.
     * @return        true nebo false, podle toho, jestli byla věc nalezena nebo ne.
     */
    public boolean maVec(String jm) {
        boolean maJi = false;
        for (Vec v : veci) {
            if (v.getNazev().equals(jm)) {
                maJi = true;
                break;
            }
        }
        return maJi;
    }

    /**
     * Metoda equals pro porovnání dvou osob. Překrývá se metoda equals ze třídy Object.
     * Dvě osoby jsou shodné, pokud mají stejný název.
     * 
     * Bližší popis metody equals je u třídy Object.
     *
     *@param   o  object, který se má porovnávat s aktuálním.
     *@return     hodnotu true, pokud má zadaný věc stejný název, jinak false.
     */
    public boolean equals (Object o) {
        if (o instanceof Osoba) {
            Osoba druha = (Osoba)o;
            return jmeno.equals(druha.jmeno);
        }
        else {
            return false;
        }
    }

    /**
     * Metoda hashCode vraci ciselny identifikator instance, ktery se pouziva pro optimalizaci ukladani
     * v dynamickych datovych strukturach. Pri prekryti metody equals je potreba prekryt i metodu hashCode.
     * Podrobny popis pravidel pro vytvareni metody hashCode je u metody hashCode ve tride Object
     */
    public int hashCode() {
        return jmeno.hashCode();
    }

    /***************************************************************************
     * Metoda toString ukazuje, jakým způsobem má být osoba jako objekt převedena na řetězec.
     */
    public String toString() {
        return jmeno+ "("+popis+")";
    }

}