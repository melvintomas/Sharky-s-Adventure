#include "Level.h"
#include <SFML/Graphics.hpp>


Level::Level(){

}

void Level::addPlat(sf::Vector2f size, sf::Color color, sf::Vector2f position){
	sf::RectangleShape plat;
	plat.setSize(size);
	plat.setFillColor(color);
	plat.setPosition(position);
	obs.push_back(plat);
}

void Level::addPlat(float sX, float sY, float pX, float pY){
	sf::RectangleShape plat;
	plat.setSize(sf::Vector2f(sX,sY));
	plat.setFillColor(sf::Color::Black);
	plat.setPosition(sf::Vector2f(pX,pY));
	obs.push_back(plat);
}
void Level::addPlat(float sX, float sY, float pX, float pY,sf::Color color){
	sf::RectangleShape plat;
	plat.setSize(sf::Vector2f(sX,sY));
	plat.setFillColor(color);
	plat.setPosition(sf::Vector2f(pX,pY));
	obs.push_back(plat);
}

void Level::loadLevel(){
	addPlat(sf::Vector2f(50,50),sf::Color::Yellow,sf::Vector2f(600,550));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(300,200));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(400,150));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(500,400));
	addPlat(sf::Vector2f(200,10),sf::Color::Magenta,sf::Vector2f(150,400));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(150,300));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(850,550));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(1250,500));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(1450,350));
	addPlat(sf::Vector2f(50,10),sf::Color::Magenta,sf::Vector2f(1650,300));

	addPlat(50,10, 1850, 300);
	addPlat(50,10, 2050, 300);
	addPlat(50,10, 2250, 300);
	addPlat(50,10, 2450, 300);
	addPlat(50,10, 2650, 300);
	addPlat(50,10, 2850, 300);
	addPlat(50,10, 3050, 300);
	addPlat(50,10, 3150, 300);
	addPlat(50,10, 3250, 300);
	addPlat(50,10, 3350, 300);
	addPlat(50,10, 3450, 300);
	addPlat(50,10, 3550, 300);
	addPlat(50,10, 3650, 300);
	addPlat(50,10, 3750, 300);
	addPlat(50,10, 3850, 300);
	addPlat(50,10, 3950, 300);
	addPlat(50,10, 4050, 300);
	addPlat(50,10, 4150, 300);
	addPlat(50,10, 4250, 300);
	addPlat(134,466,701,130);
	addPlat(58,295,2752,303);
	addPlat(195,417,4303,53);
	addPlat(305,191,4676,407);
	addPlat(40,52,4635,544);
	addPlat(317,58,5016,248);
	addPlat(139,190,5346,180);
	addPlat(489,30,5671,332);
	addPlat(421,40,6167,205);
	addPlat(47,61,4981,536);
	addPlat(84,388,6665,207);
	addPlat(422,69,6750,262);
	addPlat(176,24,7408,270);
	addPlat(190,23,7724,269);
	addPlat(218,30,8008,210);
	addPlat(293,488,8589,4);
	addPlat(228,452,9126,143);
	addPlat(64,22,9063,435);
	addPlat(61,40,8873,316);
	addPlat(51,26,9070,187);
	addPlat(136,444,9519,4);
	addPlat(141,201,9848,394);
	addPlat(56,31,9649,417);
	addPlat(183,294,10090,305);
	addPlat(35,40,9985,555);
	addPlat(217,392,10393,205);
	addPlat(67,148,10269,448);
	addPlat(331,65,10677,58);
	addPlat(248,421,11096,176);
	addPlat(58,102,10835,496);
	addPlat(73,30,10702,411);
	addPlat(67,40,10606,277);
	addPlat(168,66,11511,307);
	addPlat(145,202,11824,391);
	addPlat(70,37,11697,474);
	addPlat(256,282,12123,311);
	addPlat(45,12,12020,531);
	addPlat(170,72,12635,521);
	addPlat(157,46,12761,472);
	addPlat(144,41,12919,425);
	addPlat(124,46,13043,378);
	addPlat(120,54,13136,323);
	addPlat(113,34,13251,286);
	addPlat(119,42,13356,245);
	addPlat(325,42,13460,204);
	addPlat(296,27,13815,85);
	addPlat(337,47,14153,201);
	addPlat(172,29,14619,281);
	addPlat(214,17,15048,286);
	addPlat(101,27,14879,144);
	addPlat(67,300,15352,171);
	addPlat(465,36,15418,172);
	addPlat(607,52,15864,218);
	addPlat(83,498,16741,94);
	addPlat(95,39,16644,403);
	addPlat(57,24,16508,475);
	addPlat(90,33,16521,82);
	addPlat(303,55,17088,94);
	addPlat(40,285,17223,136);
	addPlat(64,319,17454,94);
	addPlat(61,302,17634,100);
	addPlat(119,48,17515,209);
	addPlat(58,297,17774,101);
	addPlat(132,58,17830,101);
	addPlat(78,37,17831,243);
	addPlat(122,38,17830,361);
	addPlat(62,286,18187,111);
	addPlat(146,38,18248,113);
	addPlat(81,26,18254,243);
	addPlat(133,33,18251,365);
	addPlat(73,278,18487,113);
	addPlat(39,62,18560,135);
	addPlat(35,38,18597,195);
	addPlat(29,31,18630,232);
	addPlat(34,36,18657,262);
	addPlat(27,28,18690,303);
	addPlat(17,22,18711,330);
	addPlat(27,290,18722,104);
	addPlat(17,287,18749,106);
	addPlat(52,278,18835,112);
	addPlat(39,47,18885,121);
	addPlat(29,26,18887,349);
	addPlat(42,62,18921,131);
	addPlat(26,135,18961,189);
	addPlat(-34,26,18970,322);
	addPlat(-26,18,18933,344);
	addPlat(-13,7,18939,341);
	addPlat(66,238,19072,114);
	addPlat(66,55,19072,369);
	addPlat(62,561,19607,37);
	addPlat(68,29,19179,387,sf::Color::Transparent);
	addPlat(58,27,19284,434,sf::Color::Transparent);
	addPlat(73,32,19295,247,sf::Color::Transparent);
	addPlat(75,33,19535,144,sf::Color::Transparent);
	addPlat(137,56,20180,125);
	addPlat(-54,124,20183,172);
	addPlat(110,59,20179,275);
	addPlat(45,101,20287,311);
	addPlat(-126,41,20303,410);
	addPlat(-11,289,20427,135);
	addPlat(113,10,20426,141);
	addPlat(118,2,20424,283);
	addPlat(116,14,20413,415);
	addPlat(165,13,20579,148);
	addPlat(-13,264,20594,156);
	addPlat(166,15,20587,414);
	addPlat(33,264,20797,155);
	addPlat(89,22,20830,154);
	addPlat(17,90,20916,169);
	addPlat(-93,15,20919,252);
	addPlat(26,28,20830,264);
	addPlat(18,18,20858,294);
	addPlat(21,13,20880,314);
	addPlat(10,17,20903,332);
	addPlat(7,12,20921,363);
	addPlat(19,21,20914,352);
	addPlat(16,20,20908,341);
	addPlat(31,43,20928,368);
	addPlat(36,243,21002,163);
	addPlat(70,40,21037,165);
	addPlat(47,29,21034,272);
	addPlat(70,35,21030,383);
	addPlat(152,38,21156,161);
	addPlat(38,204,21226,202);
	addPlat(41,23,21391,350);
	addPlat(59,21,21414,333);
	addPlat(44,18,21441,305);
	addPlat(51,12,21456,278);
	addPlat(42,18,21478,239);
	addPlat(72,15,21502,223);
	addPlat(29,19,21505,203);
	addPlat(25,13,21528,181);
	addPlat(27,10,21546,171);
	addPlat(31,18,21571,173);
	addPlat(22,23,21594,195);
	addPlat(45,26,21599,219);
	addPlat(39,14,21570,228);
	addPlat(43,29,21612,247);
	addPlat(44,38,21633,274);
	addPlat(26,30,21653,310);
	addPlat(22,12,21668,343);
	addPlat(51,162,21732,180);
	addPlat(75,42,21777,150);
	addPlat(79,94,21843,175);
	addPlat(63,27,21781,248);
	addPlat(33,15,21834,274);
	addPlat(24,24,21871,299);
	addPlat(19,13,21895,328);
	addPlat(37,177,21975,168);
	addPlat(75,22,22005,166);
	addPlat(35,15,22009,244);
	addPlat(91,30,22011,324);
	addPlat(53,22,22162,329);
	addPlat(54,24,22196,304);
	addPlat(39,26,22225,272);
	addPlat(36,23,22250,237);
	addPlat(43,21,22270,200);
	addPlat(81,22,22298,183);
	addPlat(34,27,22300,163);
	addPlat(24,12,22320,143);
	addPlat(29,18,22352,131);
	addPlat(9,25,22389,125);
	addPlat(19,36,22390,143);
	addPlat(22,28,22402,185);
	addPlat(39,50,22392,208);
	addPlat(41,35,22409,259);
	addPlat(31,31,22427,310);
	addPlat(39,25,22449,348);
	addPlat(94,181,22561,66);
	addPlat(127,80,22545,288);
	addPlat(75,591,23126,4);

	

}

void Level::draw(sf::RenderWindow *rw){
	for(unsigned int i=0; i< obs.size(); ++i){
			rw->draw(obs.at(i));
	}
};