import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

/**
 *  Class TextoveRozhrani
 * 
 *  Toto je uživatelského rozhraní aplikace Adventura
 *  Tato třída vytváří instanci třídy Hra, která představuje logiku aplikace.
 *  Čte vstup zadaný uživatelem a předává tento řetězec logice a vypisuje odpověď logiky na konzoli.
 *  Pokud chcete hrát tuto hru, vytvořte instanci této třídy
 *  a poté na ní vyvolejte metodu "hraj". 
 *  
 *
 *@author     Michael Kolling, Lubos Pavlicek, Jarmila Pavlickova
 *@version    pro školní rok 2009/2010
 */

class TextoveRozhrani {
    private Hra hra;

    /**
     *  Vytváří hru.
     */
    public TextoveRozhrani() {
        hra = new Hra();
    }

    /**
     *  Hlavní metoda hry. Cyklí se do konce hry (dokud metoda konecHry() z logiky nevrátí
     *  hodnotu true)
     */
    public void hraj() {
        System.out.println(hra.vratUvitani());

        // základní cyklus programu - opakovaně se čtou příkazy a poté
        // se provádějí do konce hry.

        while (!hra.konecHry()) {
            String radek = prectiString();

            System.out.println(hra.zpracujPrikaz(radek));
        }
        System.out.println(hra.vratEpilog());
    }

    /**
     *  Metoda přečte příkaz z příkazového řádku
     *
     *@return    Vrací přečtený příkaz jako instanci třídy String
     */
    private String prectiString() {
        String vstupniRadek="";
        System.out.print("> ");        // vypíše se prompt

        BufferedReader vstup =
            new BufferedReader(new InputStreamReader(System.in));
        try {
            vstupniRadek = vstup.readLine();
        }
        catch (IOException exc) {
            System.out.println("Vyskytla se chyba během čtení příkazu: "
                + exc.getMessage());
        }
        return vstupniRadek;
    }

}
