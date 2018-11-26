/* Soubor je ulozen v kodovani UTF-8.
 * Kontrola kódování: Příliš žluťoučký kůň úpěl ďábelské ódy. */



/*******************************************************************************
 * Testovací třída HraTest slouží ke komplexnímu otestování
 * třídy Hra
 *
 * @author    Jarmila Pavlíčková
 * @version  pro školní rok 2010/2011
 */
public class HraTest extends junit.framework.TestCase
{
    private Hra hra1;
    private Batoh batoh;

//== Datové atributy (statické i instancí)======================================

//== Konstruktory a tovární metody =============================================

    /***************************************************************************
     * Vytvoří instanci testovací třídy se zadaným názvem.
     *
     * @param název  Název konstruovaného testu
     */
    public HraTest(String název)
    {
        super( název );
    }

//== Příprava a úklid přípravku ================================================

    /***************************************************************************
     * Metoda se provede před spuštěním každé testovací metody. Používá se
     * k vytvoření tzv. přípravku (fixture), což jsou datové atributy (objekty),
     * s nimiž budou testovací metody pracovat.
     */
    @Override
    protected void setUp()
    {
        hra1 = new Hra();
        batoh = new Batoh(3, 10000);
    }

    /***************************************************************************
     * Úklid po testu - tato metoda se spustí po vykonání každé testovací metody.
     */
    @Override
    protected void tearDown()
    {
    }

//== Soukromé metody používané v testovacích metodách ==========================

//== Vlastní testovací metody ==================================================

 /***************************************************************************
     * Testuje průběh hry, po zavolání každěho příkazu testuje, zda hra končí
     * a v jaké aktuální místnosti se hráč nachází.
     * Při dalším rozšiřování hry doporučujeme testovat i jaké věci nebo osoby
     * jsou v místnosti a jaké věci jsou v batohu hráče.
     * 
     */
    public void testPrubehHry()
    {
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("hraj");
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("jdi park");
        assertEquals(false, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("jdi supermarket");
        assertEquals(false, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("poloz neco");
        assertEquals(false, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("kup neco");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("volej nekomu");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("vezmi neco");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("mluv nekdo");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("dej nekomu neco");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("vymen nekdo neco1 neco2");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("coje tady");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("prohledniSi neco");
        assertEquals(false, hra1.konecHry());
         assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("vydelat");
        assertEquals(false, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("napoveda");
        assertEquals(false, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
        hra1.zpracujPrikaz("konec");
        assertEquals(true, hra1.konecHry());
        assertEquals("byt", hra1.getHerniPlan().getAktualniProstor().getNazev());
    }
}

