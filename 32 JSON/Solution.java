import java.util.*;


/*
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=207714&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=210615&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3089%5D%5Bvalue%5D%5B2%5D%3D2%26searchoption%5B3089%5D%5Btype%5D%3Dcheckbox%26searchoption%5B3046%5D%5Bvalue%5D%3D39%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

第二题要深深的感谢国人哥哥帮助我，我默默的感觉他给我放水了， 是JSON的题，让我设计class JSON并写出所有function，并且用自己设计的class去除他给的JSON里的所有string.-google 1point3acres
JSON里有string, nested JSON, 要求nested JSON可以调用getKey(), getJSON(), String不可以调用这两个，只能直接返回String.我看到这个题目后内心其实是崩溃的，以为要狗带了，结果他只让我设计所有finction,呜呜，让我再次在心里默默地感谢他。 嗯，这题就是写个super class JSON,里面有type() 用来识别是String还是nested JSON,然后再另写两个子类继承这个父类，一个是nestedJSON类，用来实现getkey()和getJSON,另一个是string类，用来实现getString().嗯呢，大概这样，最后写了个recursion取出所有的string.
面完10分钟就越二面啦，超快的！大家加油~~~~~最后再次感谢国人哥哥，我要哭了/(ㄒoㄒ)/~~，原以为碰到JSON必死无疑呢
*/

//input: JSON apiData, string[] columns
//output: vector<unorder_map<string, string>>
//
//apiData = JSON({
//	 "GB": {
//			"birmington": {"apple": "20", "google": "50", ….},
//			"london": {"apple": "110", "google": "70", ….},
//			….
//	 },
//	 "US": {
//			"new york": {"apple": "100", "google": "200", ….},
//			"san francisco": {"apple": "150", "google": "50", ….},
//			….
//	 },
//	 ….
//})
//
//columns: ['country', 'city', 'store', 'rev']
//
//return: 
//[{"city": "london", "country": "GB", "rev": "70", "store": "google"},
//{"city": "london", "country": "GB", "rev": "110", "store": "apple"},
//{"city": "birmington", "country": "GB", "rev": "50", "store": "google"},
//{"city": "birmington", "country": "GB", "rev": "20", "store": "apple"},
//{"city": "san francisco", "country": "US", "rev": "50", "store": "google"}, ….].

Interface JSON {  // base class for json data type
	public JSON(String json);  // constructor
	public String toString();  // convert json data type to string that can be printed
	public String type();  // return type
}

class JSONMapping extend JSON {. From 1point 3acres bbs
	public JSON get(String key); // return value corresponding to the key
	public String[] keys(); // return all the keys
	public String type() {return "JSONMapping";}
}

class JSONString extend JSON {
	public String value(); // return the string
	public String type() {return "JSONString";}
}


public class Solution {
	public List<JSON> parseJSON (JSON apiData, String[] columns) {
		List<JSON> result = new ArrayList<>();
		helper(apiData, columns, 0, "{", + result);
		return result;
	}
	private void helper(JSON apiData, String[] columns, int index, String json, List<JSON> result) {
		if (apiData.type().equals("JSONString")) {
			json += columns[index] + ":" + apiData.value() + "}";
			result.add(new JSON(json));
			return;
		}
		if (apiData.type().equals("JSONMapping")) {
			for (String key : apiData.keys()) {
				helper(apiData.get(key), column, index + 1, json + columns[index] + ":" + key + ", ");
			}
		}
	}
	public static void main(String[] args) {
		
	}
}