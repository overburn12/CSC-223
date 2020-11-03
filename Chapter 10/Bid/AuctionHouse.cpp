#include "AuctionHouse.h"

AuctionHouse::AuctionHouse(){
    ArtworkVector.clear();
}

void AuctionHouse::AddWork(int ArtworkID, int OwnerID){
    Bid Temp1 (ArtworkID, OwnerID);
    ArtworkVector.push_back(Temp1);
}

void AuctionHouse::AddWork(int ArtworkID, int OwnerID, std::string Artist, std::string Title, double MinimumBid){
    Bid Temp1 (ArtworkID, OwnerID, Artist, Title, MinimumBid);
    ArtworkVector.push_back(Temp1);
}

bool AuctionHouse::UpdateWork(int ArtworkID, std::string Artist, std::string Title, double MinimumBid){
    for(auto& i: ArtworkVector)
        if(i.GetArtID() == ArtworkID){
            i.update_data(Artist, Title, MinimumBid);
            return true;
        }
    return false;
}

bool AuctionHouse::MakeBid(int ArtworkID, double BidAmount, int BidderID){
    for(auto& i: ArtworkVector)
        if(i.GetArtID() == ArtworkID)
            return i.make_bid(BidAmount, BidderID);
    return false;
}

bool AuctionHouse::Show(int ArtworkID){
    for(auto& i: ArtworkVector)
        if(i.GetArtID() == ArtworkID){
            i.show();
            return true;
        } 
    return false;   
}

void AuctionHouse::ShowAll(){
    std::cout << "\nShowing all Artwork in inventory:" << std::endl;
    for(auto& i: ArtworkVector)
        i.show();
}

bool AuctionHouse::RemoveWork(int ArtworkID){
    std::vector<Bid>::iterator it;
    for(it = ArtworkVector.begin(); it != ArtworkVector.end(); it++)
        if(it->GetArtID() == ArtworkID){
            it = ArtworkVector.erase(it);
            return true;
        }
    return false;
}
