class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hash;
        for(int i=0; i<paths.size(); i++){
            string folder_path;
            vector<string> files;
            resolve(paths[i], folder_path, files);
            for(int j=0; j<files.size(); j++){
                string name, content;
                getNameContent(files[j], name, content);
                string path = folder_path+"/"+name;
                hash[content].push_back(path);
            }
        }

        vector<vector<string>> ret;
        for(auto it = hash.begin(); it != hash.end(); it++){
            if(it->second.size() > 1){
                ret.push_back(it->second);
            }
        }
        return ret;
    }

private:
    void resolve(const string &s, string &folder_path, vector<string>& files){
        istringstream iss(s);
        iss>>folder_path;
        string file;
        while(!iss.eof()){
            iss>>file;
            files.push_back(file);
        }
    }
    void getNameContent(const string &file, string &name, string &content){
        int index = file.find('(');
        name = file.substr(0, index);
        content = file.substr(index);
    }
};




vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> dict; // unordered_map<content(hashed), vector<fully qualified file path>>
    for (auto& dir : paths){
        string dirPath;
        stringstream ss(dir);
        ss >> dirPath;
        while(!ss.eof()){
            string fileName;
            string contents;
            string blob;
            ss >> blob;
            size_t contentsStart;
            size_t contentsEnd;
            contentsStart =  blob.find('(');
            contentsEnd = blob.rfind(')');
            fileName = blob.substr(0, contentsStart);
            contents = blob.substr(contentsStart + 1, contentsEnd - contentsStart - 1);
            string fullPath = dirPath + "/" + fileName;
            dict[contents].push_back(fullPath);
        }
    }

    vector<vector<string>> res;
    for (auto& hash : dict){
        if (hash.second.size() < 2)
            continue;
        res.push_back(hash.second);
    }
    return res;
}
