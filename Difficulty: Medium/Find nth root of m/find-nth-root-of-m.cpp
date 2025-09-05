//Brute force : time complexity is m x n (n square)

// class Solution {
//   public:
//     int nthRoot(int n, int m) {
//         // Code here
//         int val=-1;
//         for(int i=1; i<=m; i++){
            
//             //function to multiply i , n times
//             val = power(i,n);
//             if(val==m){
//                 return i;
//             }
//             if(val>m){
//                 break; //no point in calc further if ans crosses m
//             }
            
//         }
//         return -1;
        
//     }
    
    
//     //power function to multiply i , n times
//     int power(int base, int exp){
//         // base is i ,exp is n
//         int prdt=1;
        
//         for(int j=1; j<=exp; j++){
//             // runs n(exp) times
//             prdt=prdt*base;
//         }
//         return prdt;
//     }
// };





//USING BINARY SEARCH
class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int low=1;
        int high=m;
        int mid;
        int val;
        while(low<=high){
            mid=(high-low)/2 + low;
            val=power(mid,n);
            
            if(val==m){
                return mid;
            }
            else if(val>m){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
    
    
    //power function to multiply i , n times
    int power(int mid, int n){
        int ans=1;
        while(n>0){ //keep doing until n reaches 0
            
            if(n%2==1){ //power is odd, then make it even
                ans=ans*mid;
                n=n-1;
            }
            else{  //power is even, apply formula x^2 = x^(2 x 2/2) = (x^2)^2/2
                mid=mid*mid;
                n=n/2;
            }
        }
        return ans;
    }
};