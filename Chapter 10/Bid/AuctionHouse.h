#include <vector>
#include "Bid.cpp"

class AuctionHouse{
private:
    std::vector<Bid> ArtworkVector;
public:
    AuctionHouse();
    void AddWork(int ArtworkID, int OwnerID);
    void AddWork(int ArtworkID, int OwnerID, std::string Artist, std::string Title, double MinimumBid);
    bool UpdateWork(int ArtworkID, std::string Artist, std::string Title, double MinimumBid);
    bool MakeBid(int ArtworkID, double BidAmount, int BidderID);
    bool Show(int ArtworkID);
    void ShowAll();
    bool RemoveWork(int ArtworkID);
};