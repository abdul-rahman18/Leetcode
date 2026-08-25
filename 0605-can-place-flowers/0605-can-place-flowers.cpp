class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        int cnt = 0;
        for(int i = 0; i < size; i++)
        {
            if(flowerbed[i] == 0)
            {
                bool b1 = true;
                bool b2 = true;

                if(i-1 >= 0 && flowerbed[i-1] == 1) b1 = 0;
                if(i+1 < size && flowerbed[i+1] == 1) b2 = 0;

                if(b1 && b2)
                {
                    flowerbed[i] = 1;
                    cnt++;
                }
            }

            if(cnt == n) return 1;
        }

        return cnt >= n;
    }
};