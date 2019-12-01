#include <vector>
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum rarity {GREEN,BLUE,PURPLE};
enum equipType {Weapon,Shield,Head,Chest,Boots,Amulet,Ring};


struct player
{

	int x, y,money;
	int level;
	string name;


	player() {
		x = 0, y = 0;
		level = 10;
		name = "sven";
		money = 1337;
	}


	void setplayerstats(int x, int y, int level, int money)
	{

		this->x = x;
		this->y = y;
		this->level = level;
		this->money = money;
	}

	int getX() { return x; }
	int getY() { return y; }
	int getLevel() { return level; }
	const string &getname() const { return name; }
	int getMoney() { return money; }

};

class item
{
	rarity r;
	equipType e;
	std::string itemname;

	int attack, def, speed, iq, id;
	float krit;

public:

	item() {};
	explicit item(std::string iname, int min, int max) {

		r = rarity::GREEN;
		attack = rand() % max + min;
		def = rand() % max + min;
		speed = rand() % max + min;
		iq = rand() % max + min;
		krit = rand() % max + min;
		itemname = iname;
		id = rand() % 10 + 1;

	}
	~item() {};

	//getters

	unsigned int getRarity() {
		return r;
	}

	void printRarity()
	{

		switch (r)
		{

		case 0: printf("Gruenes Item\n"); break;
		case 1: printf("Blaues Item\n"); break;
		case 2: printf("lilanes Item\n"); break;
		default: break;

		}
	}


	void printstats() const {

		printf("\nItem: %s\nStats: ", itemname.c_str());
		printf("atk: %d def: %d speed: %d iq: %d krit: %f id: %d", attack, def, speed, iq, krit,id);

	}

	const string getname() {
		return itemname;
	}


	unsigned int getid() { return id; }
	unsigned int getatk() { return attack; }
	unsigned int getdef() { return def; }
	unsigned int getspeed() { return speed; }
	unsigned int getiq() { return iq; }
	float getkrit() { return krit; }

	void setrarity(rarity r) { this->r = r; }
	void setType(equipType e) { this->e = e; }	
	void setid(int id) { this->id=id; }
	void setatk(int atk) { this->attack = atk; }
	void setdef(int def) { this->def = def; }
	void setspeed(int speed) { this->speed= speed; }
	void setiq(int iq) { this-> iq = iq; }
	void setkrit(float krit) { this-> krit = krit; }

};


class ItemHandler
{
	vector<item> items;

	
public:

	void pushitem(item &item);
	void pushitem(int count);
	void pushrandomitems();
	void printcurrentitems();

	ItemHandler() {};
	~ItemHandler() {};

	
};


class Game
{

public :
	player p;
	ItemHandler ih;




};

using namespace std;

void build_simple_doc()
{
	// Make xml: <?xml ..><Hello>World</Hello>
	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
	TiXmlElement * element = new TiXmlElement("Hello");
	TiXmlText * text = new TiXmlText("World");
	element->LinkEndChild(text);
	doc.LinkEndChild(decl);
	doc.LinkEndChild(element);
	doc.SaveFile("madeByHand.xml");
}

void build_simple_savefileTemplate()
{
	// Make xml: <?xml ..><Hello>World</Hello>
	TiXmlAttribute attrib;

	TiXmlDocument doc;
	TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
	TiXmlElement * element = new TiXmlElement("savefile");
	TiXmlText * text = new TiXmlText("World");
	element->LinkEndChild(text);
	doc.LinkEndChild(decl);
	doc.LinkEndChild(element);
	doc.SaveFile("madeByHand.xml");
}

void createSaveFile(player &pl, std::vector<item> &items)
{

	//brauche ich eigentlich, ich kann mit einer starten

	/* ein handle -> gleich zum gewünschtn objekt springen
	TiXmlElement* element = docH.FirstChildElement( "document" ).FirstChildElement( "Russian" ).Element();
	*/

}

void setWeaponType(string &weapontype, item &it)
{


	if (weapontype == "Weapon")
	{
		it.setType(equipType::Weapon);

	}
	else if (weapontype == "Shield")
	{
		it.setType(equipType::Shield);
	}
	else if (weapontype == "Head")
	{
		it.setType(equipType::Head);
	}
	else if (weapontype == "Boots")
	{
		it.setType(equipType::Boots);
	}
	else if (weapontype == "Amulet")
	{
		it.setType(equipType::Amulet);
	}
	else if (weapontype == "Ring")
	{
		it.setType(equipType::Ring);
	}
	else if (weapontype == "Chest")
	{
		it.setType(equipType::Chest);
	}

}

void loadGame(Game &g, string savefilepath)
{


	TiXmlDocument doc(savefilepath.c_str());
	std::cout << "hats geklappt?" << doc.LoadFile();


	TiXmlNode* itemnode = 0;
	TiXmlElement* ielement = 0;
	TiXmlAttribute* iattrib = 0;


	TiXmlNode* node = 0;
	TiXmlElement* element = 0;
	TiXmlAttribute* attrib = 0;

	if (doc.LoadFile())

	{
		//playerinfo name etc
		
		//wir holen uns wurzek
		node = doc.FirstChild("savefile");
		assert(node);
		//wir holen uns die wurzel als element
		element = node->ToElement();
		assert(element);
		//wir holens uns vom element das kind und holen uns das kind als knoten
		node = element->FirstChildElement();
		assert(node);
		//dann wieder zu element damit wir lesen können
		element = node->ToElement();
		assert(element);
		attrib = element->FirstAttribute();



		cout << "Attributname: " << attrib->Name() << endl;
		cout << "Attributwert: " << attrib->Value() << endl;


		//items
		itemnode = doc.FirstChild("savefile");
		assert(itemnode);
		itemnode = itemnode->FirstChild(); //holen uns kind playerinfo
		assert(itemnode);
		itemnode = itemnode->NextSibling(); //wir holen uns ITEMS
		assert(itemnode); //jetzt sollten wir bei items sein
		itemnode = itemnode->FirstChild();//wir holen uns erstes item kind
		assert(itemnode);

		while (itemnode)
		{
			item it;
			TiXmlNode* namenode = itemnode->FirstChild(); // am besten weiter zu stats und dann kinder durchgehen
			TiXmlElement* nameelement = namenode->ToElement();
			TiXmlDeclaration* decla = namenode->ToDeclaration();

			ielement = itemnode->ToElement();
			assert(ielement);
			iattrib = ielement->FirstAttribute(); //type tag zu element gemacht


			cout << "Attributname: " << iattrib->Name() << endl;
			cout << "Attributwert: " << iattrib->Value() << endl;

		
			string weapontype = iattrib->Value();
			setWeaponType(weapontype, it);
			

			string id = ielement->Attribute("id");
			it.setid(stoi(id));


			itemnode = itemnode->NextSibling();

		}





		//	doc.Print(stdout);
	}
}


void create_savefile()
{

}


int main(int argc, char *args[])
{
	srand(time(NULL));


	Game g;

	build_simple_doc();

	TiXmlDocument doc("savefile.xml");
	std::cout << "hats geklappt?" << doc.LoadFile();


	TiXmlNode* itemnode = 0;
	TiXmlElement* ielement = 0;
	TiXmlAttribute* iattrib = 0;


	TiXmlNode* node = 0;
	TiXmlElement* element = 0;
	TiXmlAttribute* attrib = 0;

	if (doc.LoadFile())

	{
		//playerinfo name etc

		//wir holen uns wurzek
		node = doc.FirstChild("savefile");
		assert(node);
		//wir holen uns die wurzel als element
		element = node->ToElement();
		assert(element);
		//wir holens uns vom element das kind und holen uns das kind als knoten
		node = element->FirstChildElement();
		assert(node);
		//dann wieder zu element damit wir lesen können
		element = node->ToElement();
		assert(element);
		attrib = element->FirstAttribute();



		cout << "Attributname: " << attrib->Name() << endl;
		cout << "Attributwert: " << attrib->Value() << endl;


		//items
		itemnode = doc.FirstChild("savefile");
		assert(itemnode);
		itemnode = itemnode->FirstChild(); //holen uns kind playerinfo
		assert(itemnode);
		itemnode = itemnode->NextSibling(); //wir holen uns ITEMS
		assert(itemnode); //jetzt sollten wir bei items sein
		itemnode = itemnode->FirstChild();//wir holen uns erstes item kind
		assert(itemnode);

		while (itemnode)
		{
			item it;
			TiXmlNode* namenode = itemnode->FirstChild(); // am besten weiter zu stats und dann kinder durchgehen
			TiXmlElement* nameelement = namenode->ToElement();
			//TiXmlDeclaration* decla = namenode->ToDeclaration();

			ielement = itemnode->ToElement();
			assert(ielement);
			iattrib = ielement->FirstAttribute(); //type tag zu element gemacht

			/*
			//cout << "Attributname: " << iattrib->Name() << endl;
			//cout << "Attributwert: " << iattrib->Value() << endl;
			*/


			cout << "nameelement: " << nameelement->GetText() << endl;

			string weapontype = iattrib->Value();
			setWeaponType(weapontype, it);


			string id = ielement->Attribute("id");
			it.setid(stoi(id));


			itemnode = itemnode->NextSibling();

		}





		//	doc.Print(stdout);
	}
	system("pause");


	return 1; 
}

void ItemHandler::pushitem(item & item)
{
	items.push_back(item);
}

void ItemHandler::pushitem(int count)
{

	string weaponname = "Schwert ";
	

	for (int i = 0; i < count; i++) 
	{
		weaponname.at(7) = static_cast<char>(i);
		item it(weaponname, 1, 10);
		items.push_back(it);

	}
}

void ItemHandler::pushrandomitems()
{
	int random = rand() % 20 + 1;

	pushitem(random);

	printf("es wurden %d items gepusht!\n",random);
}

void ItemHandler::printcurrentitems()
{

	for (unsigned int i = 0; i < items.size(); i++) {
	
		
		items[i].printstats();
	
	}
}
