package miguens.carlos.castleonthedrig;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Solution {
	static int MAXSIZEMAP = 100002;
	

public static void main(String args[]) {
	try {
		new Solution().execute();
	}catch(IOException e){}
}

	public void execute() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader( System.in ) );
		int n = new Integer(br.readLine()).intValue();
		HashMap<String, String> map = new HashMap<String, String>();
		String cursor = "";
		for (int i = 0; i < n; i++)
        {
			cursor = br.readLine();
			String[] parts = cursor.split(" ");
			map.put(parts[0], parts[1]);
        }
		String[] queries = new String[n];
		for (int i = 0; i < n; i++)
        {
			queries[i] = br.readLine();
        }
		
		for (int i = 0; i < n; i++)
		{
			if (map.get(queries[i]) == null)
				System.out.println("Not found");
			else {
				System.out.print(queries[i]);
				System.out.print("=");
				System.out.println(map.get(queries[i]));
			}
		}
	}
}
