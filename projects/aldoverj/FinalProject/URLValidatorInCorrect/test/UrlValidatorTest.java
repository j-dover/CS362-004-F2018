

import junit.framework.TestCase;
import java.util.Random;
//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   public void assertUrlTest(boolean expectedResult, boolean validatorResult, String urlInput) {
	   if (java.util.Objects.equals(expectedResult, validatorResult)) {
		   System.out.println("PASS, URL: " + urlInput);
	   }
	   else {
		   System.out.println("FAIL, Expected Result: " + expectedResult + ", URL: " + urlInput);
	   }
   }
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   UrlValidator urlVal = new UrlValidator();
	   String urlInput;
	   boolean expectedResult;
	   boolean validatorResult;
	   
	   // Testing Valid URLs
	   System.out.println("-- Manual Testing Valid URLs --");
	   expectedResult = true;
	   urlInput = "https://valid-test1.com";
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	   
	   urlInput = "hftp://valid-test2.com:80/test?action=view";
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	   
	   urlInput = "http://valid-test3.com/";
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	   
	   // Testing Invalid URLs
	   System.out.println("-- Manual testing Invalid URLs --");
	   expectedResult = false;
	   urlInput = "//valid-test1.com";		// Missing scheme
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	   
	   urlInput = "tp://valid-test2.com:80/test?action=view";	// Invalid scheme
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	   
	   urlInput = "http://valid-test3/";	// Missing component in authority
	   validatorResult = urlVal.isValid(urlInput);
	   assertUrlTest(expectedResult, validatorResult, urlInput);
	      
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid(){
	   String protocol [] = {"http://","ftp://","https://"};
	   String auth[] = {"newegg.com", "youtube.com", "reddit.com", "8.8.8.8", "gmail.com"};
	   String port [] = {":80",":1001",":8000",":10554",":123"};
	   String path [] = {"/Components/Store",
			   "/watch?v=38JFCqi_X3c", "/services/start/canvas-login.htm", "/c/en/us/support/security/asa-5505-adaptive-security-appliance/model.html#~tab-downloads",
			   "/mail/u/3/#inbox"
	   };
	   
	   //You can use this function for programming based testing
	   UrlValidator urlVal = new UrlValidator();
	   String urlInput;
	   boolean expectedResult;
	   boolean validatorResult;
	   
	   // Testing Valid URLs
	   System.out.println("-- Random Testing Valid URLs --");
	   expectedResult = true;
	   Random ran = new Random();
	   int randomProtocolIndex;
	   int randomAuthorityIndex;
	   int randomPortIndex;
	   int randomPathIndex;
	   
	   for (int i = 0; i < 1000; i++) {
		   randomProtocolIndex = ran.nextInt(5);
		   randomAuthorityIndex = ran.nextInt(5);
		   randomPortIndex = ran.nextInt(5);
		   randomPathIndex = ran.nextInt(5);
		   urlInput = protocol[randomProtocolIndex] + auth[randomAuthorityIndex] + 
				   port[randomPortIndex] + path[randomPathIndex];
		   validatorResult = urlVal.isValid(urlInput);
		   assertUrlTest(expectedResult, validatorResult, urlInput);
	   }

   }



}
