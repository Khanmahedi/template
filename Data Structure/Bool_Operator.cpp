class comp{
    public:
        bool operator()(const pair < ll ,ll > &a , const pair < ll , ll > &b){
         return a.first < b.first ;
        }
};
