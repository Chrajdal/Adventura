import java.util.*;

/**
 *  Trida Prostor - popisuje jednotlivé prostory (místnosti) hry
 *
 *  Tato třída je součástí jednoduché textové hry.
 *
 *  "Prostor" reprezentuje jedno místo (místnost, prostor, ..) ve scénáři
 *  hry. Prostor může mít sousední prostory připojené přes východy. Pro
 *  každý východ si prostor ukládá odkaz na sousedící prostor.
 *
 *@author     Michael Kolling, Lubos Pavlicek, Jarmila Pavlickova, Tomáš Jakubčin (xjakt00)
 *@version    pro školní rok 2010/2011
 */

public class Prostor {
    private String nazev;
    private String popis;
    private Set<Prostor> vychody;   // obsahuje sousední místnosti
    private Set<Vec> veci;
    private Set<Osoba> osoby;
    private boolean obchod;
    private Map <Vec, Integer> polozeneVeci;

    /**
     * Vytvoření  prostoru se zadaným popisem, např.
     * "kuchyň", "hala", "trávník před domem"
     *
     *@param  nazev     nazev prostoru, jednoznačný identifikátor, jedno slovo nebo víceslovný název bez mezer.
     *@param  popis     popis prostoru.
     *@param  obchod    tento parametr určuje, jestli je prostor obchod nebo ne, je to potřeba k rozlišování toho, kde
     *                  může hrát věci brát a kde kupovat a podobně.
     */
    public Prostor(String nazev, String popis, boolean obchod) {
        this.nazev = nazev;
        this.popis = popis;
        this.obchod = obchod;
        vychody = new HashSet<Prostor>();
        veci = new HashSet<Vec>();
        osoby = new HashSet<Osoba>();
        polozeneVeci = new HashMap <Vec, Integer>();
    }

    /**
     * Definuje východ z prostoru (sousední/vedlejsi prostor). Vzhledem k tomu, že je použit
     * Set pro uložení východů, může být sousední prostor uveden pouze jednou
     * (tj. nelze mít dvoje dveře do stejné sousední místnosti). Druhé zadání
     * stejného prostoru tiše přepíše předchozí zadání (neobjeví se žádné chybové hlášení).
     * Lze zadat též cestu ze do sebe sama.
     * 
     * @param vedlejsi prostor, který sousedi s aktualnim prostorem.
     *
     */
    public void setVychod(Prostor vedlejsi) {
        vychody.add(vedlejsi);
    }

    /**
     * Přidává věc do prostoru.
     */
    public void setVec(Vec v) {
        veci.add(v);
    }

    /**
     * Přidává osobu do prostoru.
     */
    public Osoba setOsoba(Osoba o) {
        osoby.add(o);
        return o;
    }

    /**
     * V případě, že prostor není obchod, je možné do něj pokládat určité věci.
     * Tyto věci se pak nezapisují do klasického seznamu, ale do mapy. Tato metoda
     * umožňuje přidat do mapy nový záznam, popř. jen zvětšit hodnotu.
     * 
     * @param  v      vec, které se má zvýšit hodnota (počet).
     */
    public void PridejPolozeneVeci(Vec v) {
        if (polozeneVeci.containsKey(v)) {
            polozeneVeci.put(v, polozeneVeci.get(v) + 1);
        }
        else {
            polozeneVeci.put(v, 1);
        }
    }

    /**
     * Tato metoda odebírá jeden kus dané věci.
     * 
     * @param  v     vec, kterou je nutné odebrat.
     */
    public void OdeberPolozeneVeci(Vec v) {
        polozeneVeci.put(v, polozeneVeci.get(v) - 1);
    }

    /**
     * V případě, že je počet kusů dané věci roven nule, je volána
     * tato metoda, která danou věc z prostoru úplně odstraní.
     * 
     * @param v      vec, která má být odtraněna.
     */
    public void removePolozenaVec(Vec v) {
        Iterator <Vec> ukazovatko = polozeneVeci.keySet().iterator();
        while (ukazovatko.hasNext()) {
            Vec klic = ukazovatko.next();
            if (klic == v) {
                ukazovatko.remove();
            }
        }
    }

    /**
     * Metoda equals pro porovnání dvou prostorů. Překrývá se metoda equals ze třídy Object.
     * Dva prostory jsou shodné, pokud mají stejný název.
     * Tato metoda je důležitá z hlediska správného fungování seznamu východů (Set).
     * 
     * Bližší popis metody equals je u třídy Object.
     *
     *@param   o  object, který se má porovnávat s aktuálním
     *@return     hodnotu true, pokud má zadaný prostor stejný název, jinak false
     */

    @Override
    public boolean equals (Object o) {
        if (o instanceof Prostor) {
            Prostor druhy = (Prostor)o;
            return nazev.equals(druhy.nazev);
        }
        else {
            return false;
        }
    }

    /**
     * metoda hashCode vraci ciselny identifikator instance, ktery se pouziva pro optimalizaci ukladani
     * v dynamickych datovych strukturach. Pri prekryti metody equals je potreba prekryt i metodu hashCode.
     * Podrobny popis pravidel pro vytvareni metody hashCode je u metody hashCode ve tride Object
     */

    @Override
    public int hashCode() {
        return nazev.hashCode();
    }

    /**
     * Vrací název prostoru (byl zadán při vytváření prostoru jako
     * parametr konstruktoru)
     *
     *@return    název prostoru.
     */
    public String getNazev() {
        return nazev;
    }

    /**
     * Vrací "dlouhý" popis prostoru, který může vypadat následovně:
     *      Jsi v mistnosti/prostoru vstupni hala budovy VSE na Jiznim meste.
     *      vychody: chodba, bufet, ucebna,
     *
     *@return    Dlouhý popis prostoru.
     */
    public String dlouhyPopis() {
        return "Jsi v prostoru " + nazev + ". " + popis + ".\n" + seznamVychodu();
    }

    /**
     * Vrací informaci o tom, jestli prostor je nebo není obchod.
     */
    public boolean getObchod() {
        return obchod;
    }

    /**
     *  Vrací počet kusů určité věci položených v daném prostoru.
     *  
     * @param  vecicka       věc, jejíž "četnost" chceme zjistit.
     */
    public int getPocetPolozenaVec(Vec vecicka) {
        Set <Vec> klice = polozeneVeci.keySet();
        for (Vec v : klice)
            if (v.equals(vecicka)) {
                int pocet = polozeneVeci.get(v);
                return pocet;
        }
        return 0;
    }

    /**
     *  Obdoba metody 'vyberVec'.
     *  
     * @param  jm           jméno věci.
     */
    public Vec vyberPolozenaVec(String jm) {
        Set <Vec> klice = polozeneVeci.keySet();
        for (Vec v : klice)
            if (v.getNazev().equals(jm)) {
                Vec vybranaVec = v;
                return vybranaVec;
        }
        return null;
    }

    /**
     *  Seznam všech položených věcí v místnosti.
     *  
     *  @return      vrátí seznam klíčů - věcí, které jsou v místnosti položeny.
     */
    public Set<Vec> getPolozeneVeci() {
        Set <Vec> veci = polozeneVeci.keySet();
        return veci;
    }

    /**
     * Vrací textový řetězec, který popisuje sousední východy)například:
     * "vychody: hala ".
     *
     *@return    Seznam názvů sousedních prostorů
     */
    private String seznamVychodu() {
        String vracenyText = "Vychody:";
        for (Prostor sousedni : vychody) {
            vracenyText += " " + sousedni.getNazev() + ", ";
        }
        return vracenyText;
    }

    /**
     * Vrací seznam věcí a osob, které se v místnosti nacházejí.
     * 
     * @return      vrací text, který obsahuje všechny věci i osoby v místnosti.
     */
    public String seznamVeciAOsob() {
        String vracenyText = "Veci a osoby v prostoru:";
        for (Osoba o : osoby) {
            vracenyText += " " + o.getJmeno()+" (osoba),";
        }
        if (obchod == true) {
            for (Vec v : veci) {
                vracenyText += " " + v.getNazev()+",";
            }
            return vracenyText;
        }
        else {
            Set <Vec> klice = polozeneVeci.keySet();
            for (Vec vecicka : klice) {
                vracenyText += " " + vecicka.getNazev() +"("+polozeneVeci.get(vecicka)+"x)";
            }
            return vracenyText;
        }
    }

    /**
     * Vrací prostor, který sousedí s aktuálním prostorem a jehož název je zadán
     * jako parametr. Pokud prostor s udaným jménem nesousedí s aktuálním prostorem,
     * vrací se hodnota null.
     *
     *@param  nazevSouseda  Jméno sousedního prostoru (východu)
     *@return            Prostor, který se nachází za příslušným východem, nebo
     *                   hodnota null, pokud prostor zadaného jména není sousedem.
     */
    public Prostor vratSousedniProstor(String nazevSouseda) {
        if (nazevSouseda == null) {
            return null;
        }
        for ( Prostor sousedni : vychody ){
            if (sousedni.getNazev().equals(nazevSouseda)) {
                return sousedni;
            }
        }
        return null;  // prostor nenalezen
    }

    /**
     * Vrací kolekci obsahující prostory, se kterými tento prostor sousedí.
     * Takto získaný seznam sousedních prostor nelze upravovat (přidávat, odebírat východy)
     * protože z hlediska správného návrhu je to plně záležitostí třídy Prostor.
     *
     *@return    Nemodifikovatelná kolekce prostorů (východů), se kterými tento prostor sousedí.
     */
    public Collection<Prostor> getVychody() {
        return Collections.unmodifiableCollection(vychody);
    }

    /**
     * Určí, jestli daný prostor obsahuje určitou věc.
     * 
     * @param  jm     jméno věci, kterou v prostoru hledáme.
     * @return        true nebo false, podle toho, jestli byla věc nalezena.
     */
    public boolean obsahujeVec(String jm) {
        boolean jetady = false;
        for (Vec v : veci) {
            if (v.getNazev().equals(jm)) {
                jetady = true;
                break;
            }
        }
        return jetady;
    }

    /**
     * Metoda, která se používá ke zjišťování, jestli je daná věc v prostoru a následnému
     * převádění jejího názvu jako řetězce na konkrétní obejkt.
     * 
     * @param  jm     jméno věci, kterou chceme z prostoru vyndat.
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

    /**
     * Metoda, která se používá ke zjišťování, jestli je daná osoba v prostoru a následnému
     * převádění jejího názvu jako řetězce na konkrétní obejkt.
     * 
     * @param  jm     jméno osoby, se kterou chceme dále pracovat.
     * @return        věc jako obejkt, popř. null.
     */
    public Osoba vyberOsobu(String jm) {
        for (Osoba o : osoby)
            if (o.getJmeno().equals(jm)) {
                Osoba vybranaOsoba = o;
                return vybranaOsoba;
        }
        return null;
    }
}
