class Solution{
    public:
    int largestAltitude(vector<int>& gain){
      int max = 0 ;
      int current = 0 ;
      for(int g : gain){
        current += g ;
        max = max(current, max) ;
      }
      return max; 
    }
}