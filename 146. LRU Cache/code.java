class LRUCache {

    HashMap<Integer, Integer> m;
    ArrayList<Integer> list;
    int cap;
    
    public LRUCache(int capacity) {
        m = new HashMap<Integer, Integer>();
        list = new ArrayList<Integer>();
        cap = capacity;
    }
    
    public int get(int key) {
        if(m.containsKey(key)){
            int i = list.indexOf(key);
            list.remove(i);
            list.add(key);
            return m.get(key);  
        } 
        return -1;
    }
    
    public void put(int key, int value) {
        
        if(!m.containsKey(key)){
            if(list.size()==cap){
                int t = list.get(0);
                list.remove(0);

                m.remove(t);  
                
            }
            list.add(key);
        }
        else{
            int i = list.indexOf(key);
            list.remove(i);
            list.add(key);
        }
        
        m.put(key, value);
    }
}
