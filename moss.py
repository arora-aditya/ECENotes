import mosspy
import sys

userid = "removed for privacy"

m = mosspy.Moss(userid, "cc")

# Submission Files
m.addFile(str(sys.argv[1]))
m.addFile(str(sys.argv[2]))


url = m.send() # Submission Report URL

print ("Report Url: " + url)

# # Save report file
# m.saveWebPage(url, "submission/report.html")
#
# # Download whole report locally including code diff links
# mosspy.download_report(url, "submission/report/", connections=8)
