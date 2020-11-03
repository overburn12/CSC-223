/*

Program 1: make_bid 
Traditional Expressions Auction House sells high-end artwork for clients using a silent-bid system. 
Write a program that uses a class called artwork to create objects that will store the following 
information: 

Data Member Description Artwork ID A 4-digit code assigned to an artwork. 
Each code will only be used once when it is assigned to a particular piece of art. 
Owner ID A 4-digit code assigned to an owner-client. 
An owner may have more than one artwork available for auction at any given time. 
Artist The name of the artist who created the artwork. 
Title The name of the artwork. 
Minimum Bid The minimum amount of money the owner will accept as a bid for the auction. 
Current High Bid The highest bid made so far. 
Bidder ID A 4-digit code assigned to bidders. 
This data member will hold the ID number of the bidder who has the current highest bid. 
The class should have two constructors. 

One constructor requires the artwork id and owner id to be stored to the object. 
Artist and title should be initialized to empty strings. 
Minimum bid, current high bid, and bidder id should be initialized to 0. 

The second constructor requires all members except for current high bid and bidder id 
    to be sent to the object and stored. 
Current high bid and bidder id should be initialized to 0. 

The class should have standard assessors and mutators for artist, title, and minimum bid. 

Once artwork id and owner id are set via the constructor, they should not be changed. 

The class should have a member function called make_bid(…) that sends a bid to the object. 
make_bid should accept two parameters: a bid and a bidder id. 
If the bid is equal to or higher than the minimum bid and the bid is higher than the current high bid,
store the bid to current high bid and the bidder's id to bidder id.  
If the bid is accepted, the member function should return true. 
If the bid is not higher than the current high bid, the function should return false. 

The class should have a member function called show(…) that neatly displays all data
    within the object. Label each field appropriately. 

Test your program via the following actions: 

A client submits a work to be auctioned. 
The company assigns the new item the code 1254. The owner id is 5021.
Create an object representing this item. 
Use the show member function to display the object. 

A client submits a work to be auctioned. 
The company assigns the new item the code 6373. The owner id is 1001.  
The artist is Andrea Milna. The title is Spring Day. 
The minimum bid the client will accept is $75,000. 
Use the show member function to display the object. 

Client 5021 has brought in their art work. 
Use the appropriate mutators to modify the object created earlier. 
The artist is Carl Patray. The title of the work is Afternoon Breeze. 
The lowest amount the client will accept is $35,500. 
Use the show member function to display the object. 

A bid has been made on artwork 1254. Use the make_bid member function to bid $50,000. 
Display a message indicating whether or not the bid was successful. 
If the bid is successful, show the updated object reflecting the updated current bid. 
A bid has been made on artwork 6373. Use the make_bid member function to bid $41,250. 
Display a indicating whether or not the bid was successful. 
If the bid is successful, show the updated object reflecting the updated current bid. 

*/

#include <iostream>
#include <iomanip>
#include "AuctionHouse.cpp"

int main(){
    AuctionHouse AuctionCompany;
    
    AuctionCompany.AddWork(1254, 5021);
    AuctionCompany.Show(1254);

    AuctionCompany.AddWork(6373, 1001);
    AuctionCompany.UpdateWork(6373, "Andrea Milna", "Spring Day", 75000);
    AuctionCompany.Show(6373);
    
    AuctionCompany.UpdateWork(1254, "Carl Patray", "Afternoon Breeze", 35500);
    AuctionCompany.Show(1254);

    /*---------------------------------------------------------------------------*/
    #define MakeBidAndShow(x,y,z) \
    if(AuctionCompany.MakeBid(x, y, z)){ \
        std::cout << "Succesful Bid of " << y << " on Item " << x << "! Showing Below:" << std::endl; \
        AuctionCompany.Show(x); \
    }else{ \
        std::cout << "Bid of " << y << " has not met the minimum bid for Item " << x << std::endl; \
    } 
    /*---------------------------------------------------------------------------*/

    MakeBidAndShow(1254, 50000, 1111)
    MakeBidAndShow(6373, 41250, 2222)

    #undef MakeBidAndShow

    AuctionCompany.RemoveWork(1254);
    AuctionCompany.ShowAll();

    return 0;
}