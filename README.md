This application will create all folders in the "Downloads" folder on Windows.
The folders are created based on the "filetypes.json" file. All keys for parent arrays in the JSON file are used for the folder creation. If the folder already exists, the creation is skipped. 

All values in the array are used for matching filetypes. If a filetype match is found it will be moved into the folder based on the key used for creation.

For example, if a "test.zip" file exists in the downloads folder a match will be found in the "Archives" array. This "test.zip" file will then be moved into the Archives folder. The "filetypes.json" file can be customized to your liking to create folders, and move files based on filetypes.

If you would like to add additional filetypes to the JSON file please create a pull request with the requested changes.

You do not need to recompile the application if the JSON file changes.

------------------------------------------------------------------------------

Permission is hereby  granted, free of charge, to any  person obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software  without restriction, including without  limitation the rights
to  use, copy,  modify, merge,  publish, distribute,  sublicense, and/or  sell
copies  of  the Software,  and  to  permit persons  to  whom  the Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE  IS PROVIDED "AS  IS", WITHOUT WARRANTY  OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING BUT  NOT  LIMITED TO  THE  WARRANTIES OF  MERCHANTABILITY,
FITNESS FOR  A PARTICULAR PURPOSE AND  NONINFRINGEMENT. IN NO EVENT  SHALL THE
AUTHORS  OR COPYRIGHT  HOLDERS  BE  LIABLE FOR  ANY  CLAIM,  DAMAGES OR  OTHER
LIABILITY, WHETHER IN AN ACTION OF  CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE  OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
