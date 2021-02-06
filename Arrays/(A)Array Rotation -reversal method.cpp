// methods : divide the array into two parts lets say...k, and n-k, obviously k = n%k; 

code : left rotation

reverse(arr.begin(), arr.begin()+k);
reverse(arr.begin()+k,arr.end());
reverse(arr.begin(), arr.end());

code : right rotation

reverse(arr.begin(), arr.end());
reverse(arr.begin(), arr.begin()+k);
reverse(arr.begin()+k,arr.end());

