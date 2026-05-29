class Solution {
public:

    string encode(vector<string>& strs) {
        //have base case for when strs is empty to just return an empty string
        if(strs.empty())
        {
            return "";
        }

        //init the string var that we will be returning
        string encoded = "";
        //init the int vector that will store each string's size
        vector<int> sizes;

        //loop through strs and look at each individual string s to get each string's size
        for(string& s : strs)
        {
            sizes.push_back(s.size());
        }
        //loop through sizes to form the size header of the encoded string w/ a delimiter between each
        for(int& i : sizes)
        {
            encoded += to_string(i) + ",";
        }
        //append a delimiter to represent the end of the size header
        encoded += "|";
        //loop through all the strings and then append them to the encoded string
        for(string& s : strs)
        {
            encoded += s;
        }

        //return the encoded string which contains all the strings in strs
        return encoded;
    }

    vector<string> decode(string s) {
        //have a base case for when s is empty to return an empty vector
        if(s.empty())
        {
            return {};
        }

        //init a int vector that will store all sizes in the size header
        vector<int> sizes;
        //init the string vector we will return
        vector<string> decoded;
        //init a counter i that represents the current index in string s
        int i = 0;

        /*
            read the string until the size header is finished
        */
        while(s[i] != '|')
        {
            //init a string that represents the curr size being processed
            string curr = "";
            //for each section of the string that is a single size as denoted by , append that to curr
            while(s[i] != ',')
            {
                //append curr int to curr
                curr += s[i];
                //iterate i
                i++;
            }

            //once done w/ the current size, append the size to sizes
            sizes.push_back(stoi(curr));
            //iterate i
            i++;
        }

        //iterate i past the delimiter character of |
        i++;

        //loop through sizes to process each word
        for(int size : sizes)
        {
            //push the string from the ith index to the size index onto decoded
            decoded.push_back(s.substr(i, size));
            //iterate i past the end of the substring
            i += size;
        }
        

        //return the decoded string vector
        return decoded;
    }
};
