#include <iostream>
#include <set>

using namespace std;

int main(){
    set <int>st;
    st.insert(5);
    st.insert(4);
    st.insert(3);
    st.insert(2);
    st.insert(2);

    auto it = st.find(3);

    if(it!=st.end()){
        cout<<"Found 3!"<<endl;
    }

    return 0;

}