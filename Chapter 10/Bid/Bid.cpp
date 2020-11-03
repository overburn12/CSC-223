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
    #define __SPACING std::setw(20)
    #define __HBAR "--------------------------------------"

    std::cout << std::fixed << std::setprecision(2);
    std::cout << __HBAR << std::endl;
    std::cout << __SPACING << "Artwork ID: " << ArtworkID << std::endl;
    std::cout << __SPACING << "Artwork Owner: " << OwnerID << std::endl;
    std::cout << __SPACING << "Artwork Title: " << Title << std::endl;
    std::cout << __SPACING << "Artist: " << Artist << std::endl;
    std::cout << __SPACING << "Minimum Bid: " << "$" << MinimumBid << std::endl;
    std::cout << __SPACING << "Current High Bid: " << "$" << HighBid << std::endl;
    if( HighBid != 0 )
    std::cout << __SPACING << "Current Bidder ID: " << HighBidderID << std::endl;
    std::cout << __HBAR << std::endl << std::endl;

    #undef __SPACING
    #undef __HBAR
}

int Bid::GetArtID(){
    return ArtworkID;
}