#include <string>

class Bid{
private:
    int ArtworkID;
    int OwnerID;
    std::string Artist;
    std::string Title;
    double MinimumBid;
    double HighBid;
    int HighBidderID;
public:
    Bid(int input_ArtworkID, int input_OwnerID);
    Bid(int input_ArtworkID, int input_OwnerID, std::string input_Artist, std::string input_Title, double input_MinimumBid);
    void update_data(std::string input_Artist, std::string input_Title, double input_MinimumBid);
    bool make_bid(double input_Bid, int input_BidderID);
    void show();
    int GetArtID();
};