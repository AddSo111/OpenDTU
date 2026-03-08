#include <SPI.h>
#include <Ethernet.h>

#define W5500_MOSI 12
#define W5500_MISO 11
#define W5500_SCK 10
#define W5500_CS 9

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

void initW5500()
{
    SPI.begin(W5500_SCK, W5500_MISO, W5500_MOSI, W5500_CS);
    Ethernet.init(W5500_CS);

    if (Ethernet.begin(mac) == 0)
    {
        Serial.println("DHCP failed");
    }
    else
    {
        Serial.print("Ethernet IP: ");
        Serial.println(Ethernet.localIP());
    }
}
