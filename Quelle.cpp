#include <vector>
#include "tinystr.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

enum rarity { GRAY,GREEN,BLUE,PURPLE};
enum equipType {Weapon,Shield,Head,Chest,Boots,Amulet,Ring};


struct player
{

	int x, y, money, xp;
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
	const string &getnameS() const { return name; }
	const char *getname() const { return name.c_str(); }
	int getMoney() { return money; }
	unsigned int getXP() { return xp; }

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
	void setname(string name) { this->itemname = name; }

};


class ItemHandler
{
	vector<item> items;

	
public:

	void pushitem(item &item);
	void pushitem(int count);
	void pushrandomitems();
	void printcurrentitems();


	const vector<item> &getItems() { return items; }

	ItemHandler() {};
	~ItemHandler() {};

	
};


class Game
{

public :
	player p;
	ItemHandler ih;
		   
};



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



void setWeaponType(const char *weapontype, item &it)
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

void setWeaponRarity(string &weaponrarity, item &it)
{
	if (weaponrarity == "green")
	{
		it.setrarity(rarity::GREEN);

	}
	else if (weaponrarity == "blue")
	{
		it.setrarity(rarity::BLUE);
	}
	else if (weaponrarity == "purple")
	{
		it.setrarity(rarity::PURPLE);
	}
	else  
	{
		it.setrarity(rarity::GRAY);
	}
	
}

void setWeaponRarity(const char *weaponrarity, item &it)
{
	if (weaponrarity == "green")
	{
		it.setrarity(rarity::GREEN);

	}
	else if (weaponrarity == "blue")
	{
		it.setrarity(rarity::BLUE);
	}
	else if (weaponrarity == "purple")
	{
		it.setrarity(rarity::PURPLE);
	}
	else
	{
		it.setrarity(rarity::GRAY);
	}

}



void loadGame(Game &g, string savefilepath)
{
	
	TiXmlDocument doc(savefilepath.c_str());

	if (doc.LoadFile())	cout << "xml savefile erfolgreich geladen" << endl;
	else{		cout << "xml file konnte nicht geladen werden\n";		return ;}



	if (doc.LoadFile())
	{

		TiXmlNode* playernode = 0;
		TiXmlElement* playerelement = 0;
		//playerinfo name etc
		
		//wir holen uns wurzek
		playernode = doc.FirstChild("savefile")->FirstChild(); //solten bei playerinfo sein
		assert(playernode);
		playerelement = playernode->ToElement();
		const char *playername = playerelement->Attribute("name"); //name geholt
	
		TiXmlElement *posElement = playernode->FirstChild()->ToElement();
		int posx, posy;
		posElement->QueryIntAttribute("x", &posx);
		posElement->QueryIntAttribute("y", &posy);

		TiXmlElement *statsElement = playernode->FirstChild()->NextSibling()->ToElement();
		assert(statsElement);
		int level, money, xp;
		statsElement->QueryIntAttribute("level", &level);
		statsElement->QueryIntAttribute("money", &money);
		statsElement->QueryIntAttribute("xp", &xp);


		TiXmlNode* itemsnode = 0;
	
		//items
		itemsnode = doc.FirstChild("savefile");
		assert(itemsnode);
		itemsnode = itemsnode->FirstChild(); //holen uns kind playerinfo
		assert(itemsnode);
		itemsnode = itemsnode->NextSibling(); //wir holen uns ITEMS
		assert(itemsnode); //jetzt sollten wir bei items sein
		itemsnode = itemsnode->FirstChild();//wir holen uns erstes item kind
		assert(itemsnode);

		while (itemsnode)//itemS node, its not the Items but its all items
		{
			item it;
			TiXmlElement *itemelement = itemsnode->ToElement();
			assert(itemelement);
		
			//waffentyp
			const char *weapontype = itemelement->Attribute("type");
			setWeaponType(weapontype, it);
			//waffenid
			const char *weaponid = itemelement->Attribute("id");
			string s = weaponid;
			it.setid(stoi(s));
			//waffenname
			const char *weaponname = itemelement->Attribute("name");
			it.setname(weaponname);
			const char *rarity = itemelement->Attribute("rarity");
			setWeaponRarity(rarity, it);

			//stats
			TiXmlElement *statselement  = itemsnode->FirstChild()->ToElement();
			assert(statselement);
		
			int atk, def, speed, iq; float krit;
			statselement->QueryIntAttribute("atk", &atk); // If this fails, original value is left as-is
			statselement->QueryIntAttribute("def", &def);
			statselement->QueryIntAttribute("speed", &speed);
			statselement->QueryIntAttribute("iq", &iq);
			statselement->QueryFloatAttribute("krit", &krit);
			
			it.setatk(atk);
			it.setdef(def);
			it.setspeed(speed);
			it.setiq(iq);
			it.setkrit(krit);

			g.ih.pushitem(it);

			itemsnode = itemsnode->NextSibling();

		}
	}
}

//http://www.grinninglizard.com/tinyxmldocs/tutorial0.html
void create_savefile(Game &g)
{
	TiXmlDocument doc;

	TiXmlDeclaration* decl = new TiXmlDeclaration("1.0", "", "no");
	doc.LinkEndChild(decl);

	TiXmlElement * root = new TiXmlElement("savefile");
	doc.LinkEndChild(root);


	TiXmlElement * playerinfo = new TiXmlElement("playerinfo");
	root->LinkEndChild(playerinfo);
	playerinfo->SetAttribute("name", g.p.getname());


	TiXmlElement* pos;
	pos = new TiXmlElement("pos");
	playerinfo->LinkEndChild(pos);
	pos->SetAttribute("x", std::to_string(g.p.getX()).c_str());
	pos->SetAttribute("y", std::to_string(g.p.getY()).c_str());

	pos = new TiXmlElement("stats");
	playerinfo->LinkEndChild(pos);
	pos->SetAttribute("level", std::to_string(g.p.getLevel()).c_str());
	pos->SetAttribute("money", std::to_string(g.p.getMoney()).c_str());
	pos->SetAttribute("xp", std::to_string(g.p.getXP()).c_str());
	

	TiXmlElement * items = new TiXmlElement("items");
	root->LinkEndChild(items);


	const vector<item> vitems = g.ih.getItems();
	
	for(auto const &e : vitems)
	{ 
	
		item currentitem = e;

		TiXmlElement * item;
		item = new TiXmlElement("item");
		items->LinkEndChild(item);
		item->SetAttribute("type", "Weapon");
		item->SetAttribute("id", currentitem.getid());
		item->SetAttribute("rarity", "green"); //just test, need getrarity function from items as string return shit
		item->SetAttribute("name", currentitem.getname().c_str());
		
		

		TiXmlElement * stats;
		stats = new TiXmlElement("stats");
		item->LinkEndChild(stats);
		stats->SetAttribute("atk", currentitem.getatk());
		stats->SetAttribute("def", currentitem.getdef());
		stats->SetAttribute("speed", currentitem.getspeed());
		stats->SetAttribute("iq", currentitem.getiq());
		stats->SetAttribute("krit", std::to_string(currentitem.getkrit()).c_str()); //saved as string because setattribute takes as int if parameter
	


	
	}

	


	doc.SaveFile("newsavefile.xml");
}


int main(int argc, char *args[])
{
	srand(time(NULL));

	const string savefile = "savefile.xml";
	Game g;

	loadGame(g, savefile);

	create_savefile(g);
	
	

	system("pause");

	g.ih.printcurrentitems();

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
