import java.util.HashSet;
import java.util.Set;

/*******************************************************************************
 * Třída batoh je třídou, ve které bude uložen seznam věcí, které má hráč přímo u sebe.
 * Batoh má různá omezení - vahou a počtem věcí.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/11
 */
public class Batoh
{
    private Set <Vec> veci;
    final int MAX_VECI;
    final int MAX_VAHA;
    private int pocetVeci;
    private int vaha;
    private int penize;
    private int lidiPozvanych;

    /***************************************************************************
     *  Konstruktor třídy batoh, vytváří konkrétní batoh a jeho omezení.
     *  
     *  @param  maxVeci     určuje maximální počet věcí, které se do batohu vejdou.
     *  @param  maxVaha     určuje maximální hmotnost, kterou je batoh (resp. hráč) schopen unést.
     */
    public Batoh(int maxVeci, int maxVaha) {
        veci = new HashSet <Vec> ();
        MAX_VECI = maxVeci;
        MAX_VAHA = maxVaha;
        pocetVeci = 0;
        vaha = 0;
        penize = 2000;
        lidiPozvanych = 0;
    }

    /***************************************************************************
     * Přidává věc do batohu (do seznamu věcí).
     * 
     * @param  v     věc, kterou chceme do batohu přidat.
     */
    public void setVec (Vec v) {
        veci.add(v);
    }

    /***************************************************************************
     * Nastavuje aktuální počet věcí, kontrola, jestli nepřevyšuje maximum, 
     * probíhá v příslušných třídách (PrikazKup apod.)
     * 
     * @param  pocetVeci      hodnota, o kterou se počet věcí v batohu mění,
     *                        tedy obvykle 1 nebo -1.
     */
    public void setPocetVeci (int pocetVeci) {
        this.pocetVeci = this.pocetVeci + pocetVeci;
    }

    /***************************************************************************
     * Nastavuje aktuální hmotnost, kontrola, jestli nepřevyšuje maximum, 
     * probíhá v příslušných třídách (PrikazKup apod.)
     * 
     * @param  vaha      hodnota, o kterou se hmotnost batohu mění (=hmotnost přidávané nebo
     *                   odebírané věci).
     */
    public void setVaha (int vaha) {
        this.vaha = this.vaha + vaha;
    }

    /***************************************************************************
     * Nastavuje aktuální množství peněz hráče.
     * 
     * @param  penize      hodnota, o kterou se množství peněz mění (=cena věci, popř. vydělané
     *                     peníze).
     */
    public void setPenize (int penize) {
        this.penize = this.penize - penize;
    }

    /***************************************************************************
     * Metoda na získání aktuálního počtu věcí.
     */
    public int getPocetVeci () {
        return pocetVeci;
    }

    /***************************************************************************
     * Metoda na získání aktuální hmotnosti batohu.
     */
    public int getVaha () {
        return vaha;
    }

    /***************************************************************************
     * Metoda na získání aktuálního množství peněz.
     */
    public int getPenize () {
        return penize;
    }

    /***************************************************************************
     * Metoda vypíše hmotnost a počet věcí v batohu, poté aktuální množství peněz a nakonec i všechny
     * věci, které obsahuje.
     * 
     * @return     text, který se vypíše na obrazovku.
     */
    public String seznamVeci() {
        String vracenyText = "Batoh: hmotnost: "+vaha+"g, pocet veci: "+pocetVeci+". Veci v batohu: penize: "+penize+"Kč, ";
        for (Vec v : veci) {
            vracenyText += " " + v.getNazev()+" ("+v.getVBatohu()+"x),";
        }
        return vracenyText;
    }

    /***************************************************************************
     * Metoda, která se používá ke zjišťování, jestli je daná věc v batohu a následnému
     * převádění jejího názvu jako řetězce na konkrétní obejkt.
     * 
     * @param  jm     jméno věci, kterou chceme z batohu vyndat.
     * @return        věc jako obejkt, popř. null.
     */
    public Vec vyberVec(String jm) {
        for (Vec v : veci)
            if (v.getNazev().equals(jm)) {
                Vec vybranaVec = v;
                return vybranaVec;
        }
        return null;
    }

    /***************************************************************************
     * Metoda, která odstraní danou věc z batohu.
     * 
     * @param  v     vec, kterou cehem odstranit.
     */
    public void removeVec(Vec v) {
        veci.remove(v);
    }
}
