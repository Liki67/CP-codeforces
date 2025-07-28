ll findClassy(ll L, ll R,ll classy, vector<ll>& dp) {
    if(L>R)return classy;
    ll num=L;int cnt=0;
    while(num){
        if(dp[num]!=-1) {
            cnt+=dp[num];
            break;
        }
        else if(num%10 != 0) {
            cnt++;
        }
        num=num/10;
    }dp[num]=cnt;
    if(cnt<=3)classy++;
    return findClassy(L+1,R,classy,dp);

   