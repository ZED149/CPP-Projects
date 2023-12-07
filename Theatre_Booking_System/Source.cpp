
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Event.h"
#include "LiveMusic.h"
#include "Person.h"
#include "StandUpComedy.h"
#include "PSH.h"
#include "Seat.h"
#include "Film.h"
#include <fstream>
using namespace std;



int main()
{

	//// Film
	//{}
	//Film obj(true, 200, "Seated", "Non-Allocated", "3D", "Amannah Mall");
	//obj.Print();
	//obj.BuyTicket(10);
	//obj.BuyTicket(69);
	//obj.BuyTicket(11);
	//obj.BuyTicket(20);
	//obj.BuyTicket(30);
	//obj.BuyTicket(50);
	//obj.BuyTicket(500);
	//obj.BuyTicket(301);
	//obj.BuyTicket(110);
	//obj.BuyTicket(1);
	//obj.Print();
	//obj.CancelTicket(250);
	//obj.CancelTicket(250);
	//obj.CancelTicket(50);
	//obj.CancelTicket(1);
	//obj.CancelTicket(-1);
	//obj.Print();
	//cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	//Film anobj(2, 200, "Seated", "Non-Allocated", "2D", "Packages Mall");
	//anobj.BuyTicket(10);
	//anobj.BuyTicket(69);
	//anobj.BuyTicket(11);
	//anobj.BuyTicket(20);
	//anobj.BuyTicket(30);
	//anobj.BuyTicket(50);
	//anobj.BuyTicket(500);
	//anobj.BuyTicket(301);
	//anobj.BuyTicket(110);
	//anobj.BuyTicket(1);
	//anobj.Print();
	//anobj.CancelTicket(250);
	//anobj.CancelTicket(250);
	//anobj.CancelTicket(1);
	//anobj.CancelTicket(-1);
	//anobj.Print();
	//// Live Music
	//{}
	//LiveMusic lobj(1, 300, "Standing", "Non-Allocated", "Lake City");
	//lobj.BuyTicket(10);
	//lobj.BuyTicket(69);
	//lobj.BuyTicket(11);
	//lobj.BuyTicket(20);
	//lobj.BuyTicket(30);
	//lobj.BuyTicket(50); 
	//lobj.BuyTicket(500); 
	//lobj.BuyTicket(301); 
	//lobj.BuyTicket(110); 
	//lobj.BuyTicket(1); 
	//lobj.Print();
	//lobj.CancelTicket(250);
	//lobj.CancelTicket(250);
	//lobj.CancelTicket(50);
	//lobj.CancelTicket(1);
	//lobj.CancelTicket(-1);
	//lobj.Print();

	//cout << "--------------------------------------" << endl;
	//LiveMusic lanobj(2, 300, "Standing", "Non-Allocated", "Fortress Stadium");
	//lanobj.BuyTicket(10);
	//lanobj.BuyTicket(69);
	//lanobj.BuyTicket(11);
	//lanobj.BuyTicket(20);
	//lanobj.BuyTicket(30);
	//lanobj.BuyTicket(50);
	//lanobj.BuyTicket(500);
	//lanobj.BuyTicket(301);
	//lanobj.BuyTicket(110);
	//lanobj.BuyTicket(1);
	//lanobj.Print();
	//lanobj.CancelTicket(250);
	//lanobj.CancelTicket(250);
	//lanobj.CancelTicket(1);
	//lanobj.CancelTicket(-1);
	//lanobj.Print();

	// Stand Up Comedy
	{}
	StandUpComedy obj1(0, 200, "Seated", "Allocated", "UCP");
	Person _person("salman ahmad", 0331626171, 22);
	Person _person1("awais ahmad", 0331626171, 22);
	Person _person2("rukhma shakeel", 0331626171, 22);
	Person _person3("farhana shakeel", 0331626171, 22);
	Person _person4("shakeel ahmad", 0331626171, 22);
	Person _person5("tanawush salman", 0331626171, 22);
	Person _person6("ishmal bhatti", 0331626171, 22);
	Person _person7("nazia anees", 0331626171, 22);
	Person _person8("zain anees", 0331626171, 22);
	Person _person9("shahid saleem", 0331626171, 22);
	Person _person10("shahbaz saleem", 0331626171, 22);
	Person _person11("iqbal saleem", 0331626171, 22);
	Person _person12("misbah shahid", 0331626171, 22);
	Person _person13("aatiqa iqbal", 0331626171, 22);
	Person _person14("amina shahbaz", 0331626171, 22);
	Seat seat(1);
	Seat seat1(4);
	Seat seat2(546);
	Seat seat3(49);
	Seat seat4(4);
	Seat seat5(32);
	Seat seat6(51);
	Seat seat7(18);
	Seat seat8(181);
	Seat seat9(431);
	Seat seat10(31);
	Seat seat11(167);
	Seat seat12(109);
	Seat seat13(69);
	Seat seat14(100);
	obj1.ReserveSeat(_person, seat);
	obj1.ReserveSeat(_person1, seat1);
	obj1.ReserveSeat(_person2, seat2);
	obj1.ReserveSeat(_person3, seat3);
	obj1.ReserveSeat(_person4, seat4);
	obj1.ReserveSeat(_person5, seat5);
	obj1.ReserveSeat(_person6, seat6);
	obj1.ReserveSeat(_person7, seat7);
	obj1.ReserveSeat(_person8, seat8);
	obj1.ReserveSeat(_person9, seat9);
	obj1.ReserveSeat(_person10, seat10);
	obj1.ReserveSeat(_person11, seat11);
	obj1.ReserveSeat(_person12, seat12);
	obj1.ReserveSeat(_person13, seat13);
	obj1.ReserveSeat(_person14, seat14);
	obj1.Print();
	Seat eseat(1);
	Seat eseat1(4);
	Seat eseat2(546);
	Seat eseat3(49);
	Seat eseat4(4);
	Seat eseat5(32);
	Seat eseat6(51);
	Seat eseat7(18);
	Seat eseat8(181);
	Seat eseat9(431);
	Seat eseat10(31);
	Seat eseat11(167);
	Seat eseat12(109);
	Seat eseat13(69);
	Seat eseat14(100);
	obj1.CancelSeat(_person, eseat);
	obj1.CancelSeat(_person1, eseat1);
	obj1.CancelSeat(_person2, eseat2);
	obj1.CancelSeat(_person3, eseat3);
	obj1.CancelSeat(_person4, eseat4);
	obj1.CancelSeat(_person5, eseat5);
	obj1.CancelSeat(_person6, eseat6);
	obj1.CancelSeat(_person7, eseat7);
	obj1.CancelSeat(_person8, eseat8);
	obj1.CancelSeat(_person9, eseat9);
	obj1.CancelSeat(_person10, eseat10);
	obj1.CancelSeat(_person11, eseat11);
	/*obj1.CancelSeat(_person12, eseat12);
	obj1.CancelSeat(_person13, eseat13);
	obj1.CancelSeat(_person14, eseat14);
	obj1.CancelSeat(_person14, eseat14);
	obj1.CancelSeat(_person14, eseat14);*/
	obj1.Print();
	//
	//cout << endl << endl;
	//Event::ListAllEvents();

	//LiveMusic test_lm(true, 300, "Standing", "NoN-Allocated", "TEST_LM");
	//Film test_f(true, 200, "Seated", "Non-Allocated", "IMAX", "TEST_F");
	
	Event::Initialize();

	/*obj1.Print();
	test_lm.Print();
	test_f.Print();*/
}