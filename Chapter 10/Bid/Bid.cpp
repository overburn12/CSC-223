#include <iostream>
#include <iomanip>
#include "Bid.h"

Bid::Bid(int input_ArtworkID, int input_OwnerID){
    ArtworkID = input_ArtworkID % 10000;
    OwnerID = input_OwnerID % 10000;
    HighBid = HighBidderID = 0;
    update_data("", "", 0);
}

Bid::Bid(int input_ArtworkID, int input_OwnerID, std::string input_Artist, std::string input_Title, double input_MinimumBid){
    ArtworkID = input_ArtworkID % 10000;
    OwnerID = input_OwnerID % 10000;
    HighBid = HighBidderID = 0;
    update_data(input_Artist, input_Title, input_MinimumBid);
}

void Bid::update_data(std::string input_Artist, std::string input_Title, double input_MinimumBid){
    Artist = input_Artist;
    Title = input_Title;
    MinimumBid = input_MinimumBid;
}

bool Bid::make_bid(double input_Bid, int input_BidderID){
    if(MinimumBid <= input_Bid && HighBid < input_Bid){
        HighBidderID = input_BidderID % 10000;
        HighBid = input_Bid;
        return true;
    }
    return false;
}

void Bid::show(){
    using std::cout;
    using std::endl;
    #define __SPACING std::setw(20)
    cout << "--------------------------------------" << endl;
    cout << __SPACING << "Artwork ID: " << ArtworkID << endl;
    cout << __SPACING << "Artwork Owner: " << OwnerID << endl;
    cout << __SPACING << "Artwork Title: " << Title << endl;
    cout << __SPACING << "Artist: " << Artist << endl;
    cout << __SPACING << "Minimum Bid: " << MinimumBid << endl;
    cout << __SPACING << "Current High Bid: " << HighBid << endl;
    if(HighBid != 0 )
    cout << __SPACING << "Current Bidder ID: " << HighBidderID << endl;
    #undef __SPACING
    cout << "--------------------------------------" << endl << endl;
}

int Bid::GetArtID(){
    return ArtworkID;
}