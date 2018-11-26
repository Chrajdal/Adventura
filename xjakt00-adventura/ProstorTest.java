/*******************************************************************************
 * Testovací třída ProstorTest slouží ke komplexnímu otestování
 * třídy Prostor
 *
 * @author    Jarmila Pavlíčková, Tomáš Jakubčin (xjakt00)
 * @version   pro školní rok 2010/2011
 */
public class ProstorTest extends junit.framework.TestCase
{
//== Datové atributy (statické i instancí)======================================

//== Konstruktory a tovární metody =============================================

    /***************************************************************************
     * Vytvoří instanci testovací třídy se zadaným názvem.
     *
     * @param název  Název konstruovaného testu
     */
    public ProstorTest(String název)
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

    /**
     * Testuje, zda jsou správně nastaveny průchody mezi prostory hry.
     */
    public  void testLzeProjit()
    {        
       Prostor prostor1 = new Prostor("byt", "tvuj byt", false);
       Prostor prostor2 = new Prostor("ulice1", "tudy muzes prochazet", false);
       prostor1.setVychod(prostor2);
       prostor2.setVychod(prostor1);
       assertEquals(prostor2, prostor1.vratSousedniProstor("ulice1"));
       assertEquals(prostor1, prostor2.vratSousedniProstor("byt"));
    }
    
}