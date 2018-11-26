import java.util.*;

/**
 *  Class HerniPlan - třída představující mapu adventury.
 * 
 *  Tato třída inicializuje prvky ze kterých se hra skládá:
 *  vytváří všechny prostory,
 *  propojuje je vzájemně pomocí východů 
 *  a pamatuje si aktuální prostor, ve kterém se hráč právě nachází.
 *
 *@author     Michael Kolling, Lubos Pavlicek, Jarmila Pavlickova, Tomáš Jakubčin (xjakt00)
 *@version    pro školní rok 2010/2011
 */
public class HerniPlan {
    private Prostor aktualniProstor;
    private int cas;
    private float partyBody;
    private int divkaBody;
    private Osoba paja;
    private Prostor byt;
    private int lidiPozvanych;

    /**
     *  Konstruktor který vytváří jednotlivé prostory a propojuje je pomocí východů. Přidává věci do prostorů.
     *  Jako výchozí aktuální prostor nastaví byt.
     *  
     *  @param  batoh      batoh ze hry.
     */
    public HerniPlan() {
        cas = 300;
        partyBody = 0;
        divkaBody = 0;
        lidiPozvanych = 0;
        zalozProstoryHry();

    }

    /**
     *  Vytváří jednotlivé prostory a propojuje je pomocí východů. Přidává věci do prostorů.
     *  Jako výchozí aktuální prostor nastaví byt.
     */
    private void zalozProstoryHry() {
        Prostor hrackarstvi;
        Prostor hudba;
        Prostor kvetinarstvi;
        Prostor obleceni;
        Prostor park;
        Prostor supermarket;
        Prostor bytDivky;
        Prostor ulice1;
        Prostor ulice2;
        Prostor ulice3;
        Prostor zlatnictvi;
        String divkaKvetina;
        String divkaHudba;
        String divkaObleceni;
        String divkaSperky;
        String divkaAlkohol;

        // vytvářejí se jednotlivé prostory
        byt = new Prostor("byt","Zde muzes vydelavat a telefonovat", false);
        hrackarstvi = new Prostor("hrackarstvi", "Zde koupis plysaky, balonky a dalsi hracky", true);
        hudba = new Prostor("musicShop","Zde koupis hudebni cd", true);
        kvetinarstvi = new Prostor("kvetinarstvi","Zde koupis kvetiny", true);
        obleceni = new Prostor("obchodSoblecenim","Zde koupis tricka, mikiny a dalsi obleceni", true);
        park = new Prostor("park","Tudy muzes prochazet", false);
        supermarket = new Prostor("supermarket","Zde koupis temer vsechno", true);
        bytDivky = new Prostor("bytDivky","Zde bydli tvoje divka", false);
        ulice1 = new Prostor("ulice1","Tudy muzes prochazet", false);
        ulice2 = new Prostor("ulice2","Tudy muzes prochazet", false);
        ulice3 = new Prostor("ulice3","Tudy muzes prochazet", false);
        zlatnictvi = new Prostor("zlatnictvi","Zde koupis sperky", true);

        // vytvářejí se věci v místnostech
        hrackarstvi.setVec (new Vec ("balonky", "nafukovaci balonky", true, 20, 50, 10, -10));
        hrackarstvi.setVec (new Vec ("malyPlysak", "maly plysovy medvidek", true, 180, 120, -5, 41));
        hrackarstvi.setVec (new Vec ("velkyPlysak", "velky plysovy medvidek", true, 500, 300, -10, 105));
        hrackarstvi.setVec (new Vec ("auticko", "maly anglicak", true, 250, 60, 5, -10));

        hudba.setVec (new Vec ("Eminem", "nejnovejsi cd Eminema", true, 100, 350, 40, 11));
        hudba.setVec (new Vec ("Offspring", "nejnovejsi cd Offspring", true, 100, 330, 37, 10));
        hudba.setVec (new Vec ("blink-182", "starsi cd blink-182", true, 100, 300, 34, 7));
        hudba.setVec (new Vec ("Madonna", "nejnovejsi cd Madonny", true, 100, 380, 43, 13));
        hudba.setVec (new Vec ("Marpo", "nejnovejsi cd Marpa", true, 100, 150, 15, 3));
        hudba.setVec (new Vec ("VypsanaFixa", "nejnovejsi cd Vypsane Fixy", true, 100, 250, 28, 7));
        hudba.setVec (new Vec ("EvaAVasek", "bila orchidej od Evy a Vaska", true, 100, 220, -30, -20));

        kvetinarstvi.setVec (new Vec ("ruze", "krasna cervena ruze", true, 70, 50, -1, 20));
        kvetinarstvi.setVec (new Vec ("lilie", "krasna zluta lilie", true, 70, 70, -1, 26));
        kvetinarstvi.setVec (new Vec ("orchidej", "krasna bila orchidej", true, 70, 60, -1, 23));
        kvetinarstvi.setVec (new Vec ("listy", "listy jako ozdoba ke kytce", true, 20 , 30, -1, 10));

        obleceni.setVec (new Vec ("triko", "pekne znackove tricko", true, 90, 250, 0, 93));
        obleceni.setVec (new Vec ("kalhoty", "pekne znackove kalhoty", true, 160, 690, 0, 255));
        obleceni.setVec (new Vec ("mikina", "pekna znackova mikina", true, 150, 500, 0, 185));
        obleceni.setVec (new Vec ("spodniPradlo", "pekne znackove spodni pradlo", true, 10, 420, 10, 155));
        obleceni.setVec (new Vec ("kostym", "zabavny kostym", true, 180, 350, 40, 5));

        supermarket.setVec (new Vec ("chipsy", "dobre bramburky", true, 120, 29, 5, -10));
        supermarket.setVec (new Vec ("rum", "neco k piti", true, 550, 120, 30, 5));
        supermarket.setVec (new Vec ("vodka", "neco k piti", true, 550, 80, 20, 5));
        supermarket.setVec (new Vec ("basaPiva", "neco k piti", true, 10000, 200, 55, 5));
        supermarket.setVec (new Vec ("vino", "neco k piti", true, 550, 180, 45, 70));
        supermarket.setVec (new Vec ("cigarety", "levne cigarety", true, 50, 60, 10, -5));
        supermarket.setVec (new Vec ("chlebicky", "vsechno, co je potreba k priprave chlebicku", 
                true, 800, 130, 25, -10));

        zlatnictvi.setVec (new Vec ("zlateNausnice", "nausnice vyrobene ze zlata", true, 5, 2800, 0, 930));
        zlatnictvi.setVec (new Vec ("stribrneNausnice", "nausnice vyrobene ze stribra", true, 4, 600, 0, 200));
        zlatnictvi.setVec (new Vec ("nausnice", "bizuterie", true, 2, 230, 0, 75));
        zlatnictvi.setVec (new Vec ("zlatyPrstynek", "prstynek vyrobeny ze zlata", true, 5, 1900, 0, 630));
        zlatnictvi.setVec (new Vec ("stribrnyPrstynek", "prstynek vyrobeny ze stribra", true, 3,5250, 0, 82));
        zlatnictvi.setVec (new Vec ("prstynek", "bizuterie", true, 1, 30, 0, 10));

        // přiřazují se průchody mezi prostory (sousedící místnosti)
        byt.setVychod(ulice1);
        hrackarstvi.setVychod(ulice1);
        hudba.setVychod(ulice1);
        hudba.setVychod(ulice3);
        kvetinarstvi.setVychod(ulice1);
        kvetinarstvi.setVychod(park);
        obleceni.setVychod(ulice2);
        obleceni.setVychod(ulice3);
        park.setVychod(ulice1);
        park.setVychod(ulice2);
        park.setVychod(kvetinarstvi);
        park.setVychod(supermarket);
        supermarket.setVychod(park);
        supermarket.setVychod(ulice2);
        bytDivky.setVychod(ulice3);
        ulice1.setVychod(byt);
        ulice1.setVychod(hrackarstvi);
        ulice1.setVychod(hudba);
        ulice1.setVychod(kvetinarstvi);
        ulice1.setVychod(park);
        ulice1.setVychod(ulice3);
        ulice1.setVychod(zlatnictvi);
        ulice2.setVychod(obleceni);
        ulice2.setVychod(park);
        ulice2.setVychod(supermarket);
        ulice2.setVychod(ulice3);
        ulice3.setVychod(hudba);
        ulice3.setVychod(obleceni);
        ulice3.setVychod(bytDivky);
        ulice3.setVychod(ulice1);
        ulice3.setVychod(ulice2);
        zlatnictvi.setVychod(ulice1);

        aktualniProstor = byt;  // hra začíná v prostoru byt

        // Divka
        Random rand = new Random();
        Vec proDivku = null;
        int divkaKvetinaR = Math.abs(rand.nextInt()%2);
        switch (divkaKvetinaR){
            case 0: divkaKvetina = "ruze"; proDivku = kvetinarstvi.vyberVec(divkaKvetina); proDivku.setDivka(10); break; 
            case 1: divkaKvetina = "lilie"; proDivku = kvetinarstvi.vyberVec(divkaKvetina); proDivku.setDivka(10); break; 
            case 2: divkaKvetina = "orchidej"; proDivku = kvetinarstvi.vyberVec(divkaKvetina); proDivku.setDivka(10); break;
            default: divkaKvetina = "zadna"; break;
        }
        int divkaHudbaR = Math.abs(rand.nextInt()%6);
        switch (divkaHudbaR){
            case 0: divkaHudba = "Eminem"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break;
            case 1: divkaHudba = "Offspring"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break; 
            case 2: divkaHudba = "blink-182"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break;
            case 3: divkaHudba = "Madonna"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break;
            case 4: divkaHudba = "Marpo"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break;
            case 5: divkaHudba = "VypsanaFixa"; proDivku = hudba.vyberVec(divkaHudba); proDivku.setDivka(10); break;
            default: divkaHudba = "zadne"; break;
        }
        int divkaObleceniR = Math.abs(rand.nextInt()%4);
        switch (divkaObleceniR){
            case 0: divkaObleceni = "triko"; proDivku = obleceni.vyberVec(divkaObleceni); proDivku.setDivka(10); break;
            case 1: divkaObleceni = "kalhoty"; proDivku = obleceni.vyberVec(divkaObleceni); proDivku.setDivka(10); break;
            case 2: divkaObleceni = "mikina"; proDivku = obleceni.vyberVec(divkaObleceni); proDivku.setDivka(10); break;
            case 3: divkaObleceni = "spodniPradlo"; proDivku = obleceni.vyberVec(divkaObleceni); proDivku.setDivka(10); break;
            case 4: divkaObleceni = "kostym"; proDivku = obleceni.vyberVec(divkaObleceni); proDivku.setDivka(10); break;
            default: divkaObleceni = "zadne"; break;
        }
        int divkaSperkyR = Math.abs(rand.nextInt()%5);
        switch (divkaSperkyR){
            case 0: divkaSperky = "zlateNausnice"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            case 1: divkaSperky = "stribrneNausnice"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            case 2: divkaSperky = "nausnice"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            case 3: divkaSperky = "zlatyPrstynek"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            case 4: divkaSperky = "stribrnyPrstynek"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            case 5: divkaSperky = "prstynek"; proDivku = zlatnictvi.vyberVec(divkaSperky); proDivku.setDivka(10); break;
            default: divkaSperky = "zadne"; break;
        }
        int divkaAlkoholR = Math.abs(rand.nextInt()%3);
        switch (divkaAlkoholR){
            case 0: divkaAlkohol = "rum"; proDivku = supermarket.vyberVec(divkaAlkohol); proDivku.setDivka(10); break;
            case 1: divkaAlkohol = "vodka"; proDivku = supermarket.vyberVec(divkaAlkohol); proDivku.setDivka(10); break;
            case 2: divkaAlkohol = "basaPiva"; proDivku = supermarket.vyberVec(divkaAlkohol); proDivku.setDivka(10); break;
            case 3: divkaAlkohol = "vino"; proDivku = supermarket.vyberVec(divkaAlkohol); proDivku.setDivka(10); break;
            default: divkaAlkohol = "zadny"; break;
        }

        // Vytvareji se osoby v mistnostech
        String [] bezdomovecMluvPred = {"Bezdomovec: 'Hele, kamo, mam tady mobil, nechces? Dam ti ho za dve krabicky.' \n"
                +"Ty: 'To bude urcite ten muj, co sem ho vcera zratil. No co, asi mi nezbyde nez pro ty cigarety zajit.'", "Bezdomovec: 'Pst, pod sem' \n"
                +"Ty: 'Promin, specham, mozna potom.'"};
        String [] bezdomovecMluvPo = {"Bezdomovec: 'dik za ty cigara, kamo'"};
        Osoba bezdomovec = park.setOsoba (new Osoba ("bezdomovec", "pachnouci bezdomovec", bezdomovecMluvPred, bezdomovecMluvPo, "cigarety", 2, false));
        bezdomovec.setVec (new Vec ("mobil", "tvuj ztraceny mobil", true, 120, 3500, 0, 0));

        String [] pajaMluvPred = { "Paja: 'Moc se tesim na vecer.'", "Paja: 'Vcera jsem byla s kamaradkou venku, bylo to super.'", "Paja: 'Slusi mi to dneska? Co myslis?'", 
                "Paja: 'Moje nejoblibenejsi kytka je rozhodne "+divkaKvetina+"'", "Paja: 'Nejradsi si pustim "+divkaHudba+"'", 
                "Paja: 'Docela by se mi ted hodilo nejaky obleceni, treba "+divkaObleceni+".'", "Paja: 'Hrozne bych si prala "+divkaSperky+".'",
                "Paja: 'No, vzdyt vis, ze moc nepiju, ale kdyz uz, tak bych jedine "+divkaAlkohol+".'", "Paja: 'Segra je ted nejaka nemocna, snad to nechytnu od ni.'", 
                "Paja: 'Vis, ze budeme mit pejska? To je super, vid?'"};
        paja = bytDivky.setOsoba (new Osoba ("Paja", "tvoje divka", pajaMluvPred, pajaMluvPred, null, 0, true));
    }  

    /**
     * Metoda vrací odkaz na aktuální prostor, ve ktetém se hráč právě nachází.
     *
     *@return     aktuální prostor
     */

    public Prostor getAktualniProstor() {
        return aktualniProstor;
    }

    /**
     * Vrátí čas, který zbývá do konce hry. Tento čas se snižuje s téměř každou hráčovou činností.
     */

    public int getCas() {
        return cas;
    }

    /***************************************************************************
     * Metoda na získání aktuálního množství pozvaných lidí.
     */
    public int getLidiPozvanych () {
        return lidiPozvanych;
    }

    /***************************************************************************
     * Nastavuje aktuální množství lidí, kteří jsou pozvaní na party
     * 
     * @param  lidi      hodnota, o kterou se množství lidí změní.
     */
    public void setLidiPozvanych (int lidiPozvanych) {
        this.lidiPozvanych = this.lidiPozvanych + lidiPozvanych;
    }

    /**
     * Mění hodnotu čas.
     */

    public void setCas(int cas) {
        this.cas = this.cas - cas;
    }

    /**
     * Ukončí hru ve chvíli, kdy dojde čas. Spočítá body a vyhodnotí je.
     */

    public void konecHry()
    {
        for (Vec vecDivky : paja.getVeci()) {
            divkaBody = divkaBody + vecDivky.getDivka();
        }
        int lidiPozvanych = this.getLidiPozvanych();
        lidiPozvanych = lidiPozvanych + 2;
        partyBody = partyBody + (lidiPozvanych*10);
        float pocet;
        float cislo1;
        float cislo2;
        float cislo3;
        for (Vec vecByt : byt.getPolozeneVeci()) {
            pocet = byt.getPocetPolozenaVec(vecByt);
            cislo1 = lidiPozvanych-pocet;
            cislo2 = ((cislo1*cislo1)/10);
            cislo3 = pocet-cislo2;
            partyBody = partyBody + (vecByt.getParty()*cislo3);
        }
        System.out.println("*********** Cas vyprsel ********** \n"+
            "Konecne zacala party, ktera se nakonec protahla do velmi brzkych rannich hodin. \n"+
            "Hodnoceni vasi party je nasledujici: "+partyBody+" bodu! \n"+
            "Vase divka vas ohodnotila na " +divkaBody+" bodu! \n"+
            "Timto hra konci. Doufam, ze jste si ji uzili. Nyni muzete hru ukoncit prikazem 'konec', \n"+
            "anebo pokracovat v hrani jen tak. Ahoj!");
    }

    /**
     *  Metoda nastaví aktuální prostor, používá se nejčastěji při přechodu mezi prostory
     *
     *@param  prostor nový aktuální prostor
     */
    public void setAktualniProstor(Prostor prostor) {
        aktualniProstor = prostor;
    }
}
