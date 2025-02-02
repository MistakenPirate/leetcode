class Solution{
public:
    vector<int> asteroidCollision(vector<int> &asteroids){
        int n = asteroids.size();
        vector<int> st;
        
        for(int i = 0; i < n; i++){
            //push the asteroid in stack 
            //if a right moving asteroid is seen
            if(asteroids[i] > 0)
                st.push_back(asteroids[i]);
            //else if the asteroid is moving right
            //perform the collision
            else{
                //until the right moving asteroids
                //are smaller in size, keep on
                //destroying them
                while(!st.empty() && st.back() > 0 
                && st.back() < abs(asteroids[i]))
                    //destroy the asteroid
                    st.pop_back();
                //if there is right moving asteroid
                //which is of the same size
                if(!st.empty() &&
                    st.back() == abs(asteroids[i]))
                    //destroy both the asteroids
                    st.pop_back();
                
                //otherwise if there is no left
                //moving asteroid, the right moving
                //asteroid will not be destroyed
                else if(st.empty() ||
                        st.back() < 0)
                            //store the array in final state
                            st.push_back(asteroids[i]);
            }
        }
        //return final state of asteroids
        return st;
    }
};