

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
   
   
   public void partitionTestValidator(UrlValidator urlTest, boolean[] expectedResults)
   {
      String[] testUrls = {"http://www.google.com",
              "hcp://www.google.com",
              "https://www.reddit.com/r/movies",
              "https://www.reddit.com/r/movies#five",
              "http://www.reddit.com//r/movies",
              "www.google.com",
              "ftp://localhost"};
      boolean validatorResult;

      for (int i = 0; i < testUrls.length; i++)
      {
         try
         {
            validatorResult = urlTest.isValid(testUrls[i]);
            assertUrlTest(expectedResults[i], validatorResult, testUrls[i]);
         }
         catch (Error e)
         {
            System.out.println("Failed: " + e.getMessage());
         }
      }
   }
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing
      String[] schemes = {"http",
              "https",
              "hcp",
              "ftp"};

      System.out.println("-- Partition Testing URLs --\n");

      // Testing Basic URLValidator
      System.out.println("-- Basic UrlValidator Test --");
      UrlValidator urlTest1 = new UrlValidator();
      boolean[] expectedResults1 = {true, false, true, true, false, false, false};
      partitionTestValidator(urlTest1, expectedResults1);

      // Testing URLValidator with custom schemes
      System.out.println("\n-- UrlValidator with Schemes --");
      UrlValidator urlTest2 = new UrlValidator(schemes);
      boolean[] expectedResults2 = {true, true, true, true, false, false, false};
      partitionTestValidator(urlTest2, expectedResults2);

      // Testing URLValidator that allows all schemes
      System.out.println("\n-- UrlValidator with ALLOW_ALL_SCHEMES option --");
      UrlValidator urlTest3 = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
      boolean[] expectedResults3 = {true, true, true, true, false, false, false};
      partitionTestValidator(urlTest3, expectedResults3);

      // Testing URLValidator that allows 2 slashes in the URL path
      System.out.println("\n-- UrlValidator with ALLOW_2_SLASHES option --");
      UrlValidator urlTest4 = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);
      boolean[] expectedResults4 = {true, false, true, true, true, false, false};
      partitionTestValidator(urlTest4, expectedResults4);

      // Testing URLValidator that does not allow a fragment in the URL
      System.out.println("\n-- UrlValidator with NO_FRAGMENTS option --");
      UrlValidator urlTest5 = new UrlValidator(UrlValidator.NO_FRAGMENTS);
      boolean[] expectedResults5 = {true, true, true, false, false, false, false};
      partitionTestValidator(urlTest5, expectedResults5);

      // Testing URLValidator that allows localhost
      System.out.println("\n-- UrlValidator with ALLOW_LOCAL_URLS option --");
      UrlValidator urlTest6 = new UrlValidator(UrlValidator.ALLOW_LOCAL_URLS);
      boolean[] expectedResults6 = {true, true, true, true, false, false, true};
      partitionTestValidator(urlTest6, expectedResults6);

      // Testing URLValidator that does not allow a fragment in the URL with custom schemes
      System.out.println("\n-- UrlValidator with Schemes and NO_FRAGMENTS option --");
      UrlValidator urlTest7 = new UrlValidator(schemes, UrlValidator.NO_FRAGMENTS);
      boolean[] expectedResults7 = {true, true, true, false, false, false, false};
      partitionTestValidator(urlTest7, expectedResults7);

      // Testing URLValidator that allows 2 slashes in the URL path with custom schemes
      System.out.println("\n-- UrlValidator with Schemes and ALLOW_2_SLASHES option --");
      UrlValidator urlTest8 = new UrlValidator(schemes, UrlValidator.ALLOW_2_SLASHES);
      boolean[] expectedResults8 = {true, true, true, true, true, false, false};
      partitionTestValidator(urlTest8, expectedResults8);

      // Testing URLValidator that allows localhost with custom schemes
      System.out.println("\n-- UrlValidator with Schemes and ALLOW_LOCAL_URLS option --");
      UrlValidator urlTest9 = new UrlValidator(schemes, UrlValidator.ALLOW_LOCAL_URLS);
      boolean[] expectedResults9 = {true, true, true, true, false, false, true};
      partitionTestValidator(urlTest9, expectedResults9);

      System.out.println("\n-- End Partition Testing --");
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
		   urlInput = protocol[randomProtocolIndex] + auth[randomAuthorityIndex] + port[randomPortIndex] + path[randomPathIndex];
		   validatorResult = urlVal.isValid(urlInput);
		   assertUrlTest(expectedResult, validatorResult, urlInput);
	   }

   }



}
