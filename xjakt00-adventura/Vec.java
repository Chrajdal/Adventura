/*******************************************************************************
 * Třída Vec představuje veškeré předměty, které jsou ve hře použity.
 *
 * @author    Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/2011
 */
public class Vec
{
    private String nazev;
    private String popis;
    private boolean prenosna;
    private int vaha;
    private int cena;
    private int party;
    private int divka;
    private int vBatohu;

    /***************************************************************************
     * Vytvoří konrkétní věc do určité místnosti. Například 'lednice', 'mic', ...
     * 
     * @param  nazev      nazev prostoru, jednoznačný identifikátor, jedno slovo nebo víceslovný název bez mezer.
     * @param  popis      kratky popis veci, zobrazi se pouze pomoci prikazu 'prohledniSi'.
     * @param  prenosna   urcuje, jestli může hráč věc vzít do batohu a přenášet.
     * @param  vaha       hmotnost věci.
     * @param  cena       cena, za kterou hráč věc sežene v obchodě.
     * @param  party      hodnota, kterou věc přidá hráči na konci hry do skóre za party.
     * @param  divka      hodnota, kterou věc přidá hráči na konci hry do skóre za spokojenost jeho dívky.
     */
    public Vec(String nazev, String popis, boolean prenosna, int vaha, int cena, int party, int divka)
    {
        this.nazev = nazev;
        this.popis = popis;
        this.prenosna = prenosna;
        this.vaha = vaha;
        this.cena = cena;
        this.party = party;
        this.divka = divka;
        this.vBatohu = 0;
    }

    /***************************************************************************
     * Vrací informaci o tom, jestli je věc přenosná.
     */
    public boolean isPrenosna () {
        return prenosna;
    }

    /***************************************************************************
     * Vrací informaci o tom, kolik gramů věc váží.
     */
    public int getVaha() {
        return vaha;
    }

    /***************************************************************************
     * Vrací informaci o názvu věci.
     */
    public String getNazev() {
        return nazev;
    }

    /***************************************************************************
     * Vrací popis věci.
     */
    public String getPopis() {
        return popis;
    }

    /***************************************************************************
     * Vrací informaci o ceně věci.
     */
    public int getCena() {
        return cena;
    }

    /***************************************************************************
     * Vrací hodnotu, kterou věc přidá do konečného hráčova skóre za uspořádanou party.
     */
    public int getParty() {
        return party;
    }

    /***************************************************************************
     * Vrací hodnotu, kterou věc přidá do konečného hráčova skóre za spokojenost dívky.
     */
    public int getDivka() {
        return divka;
    }

    /***************************************************************************
     * Vrací hodnotu, která určuje, kolik těchto předmětů má hráč v batohu.
     */
    public int getVBatohu() {
        return vBatohu;
    }

    /***************************************************************************
     * Nastavuje hodnotu proměnné dívka.
     * 
     * @param  divka     určuje novou hodnotu proměnné.
     */
    public void setDivka(int divka) {
        this.divka = this.divka + divka;
    }

    /***************************************************************************
     * Nastavuje počet dané věci v batohu. Používá se při vkládání/vyndávání věc z batohu.
     * 
     * @param  vBatou     určuje novou hodnotu proměnné.
     */
    public void setVBatohu(int vBatohu) {
        this.vBatohu = this.vBatohu + vBatohu;
    }

    /**
     * Metoda equals pro porovnání dvou věcí. Překrývá se metoda equals ze třídy Object.
     * Dvě věci jsou shodné, pokud mají stejný název.
     * 
     * Bližší popis metody equals je u třídy Object.
     *
     *@param   o  object, který se má porovnávat s aktuálním.
     *@return     hodnotu true, pokud má zadaný věc stejný název, jinak false.
     */
    public boolean equals (Object o) {
        if (o instanceof Vec) {
            Vec druha = (Vec)o;
            return nazev.equals(druha.nazev);
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
        return nazev.hashCode();
    }

    /***************************************************************************
     * Metoda toString ukazuje, jakým způsobem má být věc jako objekt převedena na řetězec.
     */
    public String toString() {
        return nazev+ "("+popis+")";
    }

}