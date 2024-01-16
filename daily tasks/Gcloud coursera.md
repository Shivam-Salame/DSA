Gcloud coursera:


week-3:
Resources and Access in the cloud:
    Gcloud resource hierarchy
    Identity and Access Management:
        There are several kinds of roles in IAM:
            Basic roles: Roles historically available in the Google Cloud console. These roles are Owner, Editor, and Viewer.
                Caution: Basic roles include thousands of permissions across all Google Cloud services. In production environments, do not grant basic roles unless there is no alternative. Instead, grant the most limited predefined roles or custom roles that meet your needs.
            Predefined roles: Roles that give finer-grained access control than the basic roles. For example, the predefined role Pub/Sub Publisher (roles/pubsub.publisher) provides access to only publish messages to a Pub/Sub topic.
            Custom roles: Roles that you create to tailor permissions to the needs of your organization when predefined roles don't meet your needs.
        Role binding: principals ( google account,  service account ) + role ( App engine admin )
            This model for access management has three main parts:
                Principal. A principal can be a Google Account (for end users), a service account (for applications and compute workloads), a Google group, or a Google Workspace account or Cloud Identity domain that can access a resource. Each principal has its own identifier, which is typically an email address.
                Role. A role is a collection of permissions. Permissions determine what operations are allowed on a resource. When you grant a role to a principal, you grant all the permissions that the role contains.
                Policy. The allow policy is a collection of role bindings that bind one or more principals to individual roles. When you want to define who (principal) has what type of access (role) on a resource, you create an allow policy and attach it to the resource.
    Service Accounts
    Cloud Identity
    Interating with Gcloud 
    Interacting with gcloud:
        Gcloud console
        Cloud sdk and cloud shell
        Api
        Gcloud app
    Qwik Lab : create a deployment lamp stack

week-4:
Virtual Machines and Networks in the cloud: ( Custom and Default vpc ) - A secure, individual, private cloud-computing model  hosted within a public cloud
    Virtual Private Cloud networking :
        It has Routing tables:
            Routing tables are built-in
            No router provisioning  or managing
            Forward traffic from  one instances to another
    Compute Engine - ( sustained-use discounts, commited-use discounts, Preemtible and spot VMs)
        spot VMs:
            More features
            No maximum runtime
            Same pricing
        Preemtible VMs:
            Less features
            Runtime upto 24 hrs
            Same pricing
   
    Scaling virtual:

    Important VPC compatibilities:
        Firewall:
            No router provisioning  or managing
            Restrict access to instances
            Rules can be defined through network tags
        Vpc-peering:
            A relationship between two vpc can be establish to exchange traffic
            To use the full power of IAM  - we can configure a shared vpc
    Cloud Load Balancing:
        Global HTTP(s)
        Global SSl proxy
        Global Tcp proxy
        Regional
        Regional internal
        Internal HTTP(s) - uses proxy
    Cloud DNS and Cloud CDN:
        Google has highly developed DNS infrastructure  that makes 8.8.8.8 available so that everyone can take advantage of it
        Cloud DNS:
            Managed DNS service that runs on the same infrastructure as Google
            Low latency, HA, and cost-effective
            The DNS information you publishe is served from redundant locations around the world
            Cloud DNS is programmable. You can publish and manage millions of DNS zones and record using the Google cloud console, the cli or api
            Egde caches:
            Cloud CDN:
                Lower network latency 
                Origin of content will experience reduced load
                save money 
                Enabled with a single checkbox
    Connecting networks to Google VPC:
        IPsec VPN protocol:
            uses cloud router to make the connection dynamic
            Lets other networks and Google VPC exchage  route information  over the  VPN using the Border Gateway protocol
            Not always the best option  because of security concerns or bandwidth reliability 
        Direct peering:
            Puts a router in the same datacenter as a google point of presence(PoP)
            Uses a router to exchange traffic between networks
        Career Peering:
            Gives you direct access from an on-premises network through  a service  provider's network
            Not covered by a google service level aggrement
        Dedicated Interconnect:
            Allows one or more direct, private connections to google
            Can be covered by upto 99.99% SLA
        Partner Interconnect: 
    Qwik Lab: 
        VPC woking with routes and firewall rules

week-5:
Storage in the Cloud:
    Gcloud storage options:
        Types of data:
            Structured
            Unstructured
            Transactional
            Relational
        Storage options:
            Cloud storage
            Cloud SQL
            CLoud Spanner
            Firestore
            Cloud Bigtable
    Cloud storage:
        Object storage != File or Block storage:
            Object packaged format contains:
                Binary form of the actual data
                Relevant associated metadata
                Globally unique identifier
            note: these unique keys are in the form of url
        use case: 
            Website content
            Archival & disaster recovery
            Direct Download
        BLOB ( binary large object ):
            Online content
            Backup and archiving
            Storage of intermediate results
        Cloud storage are organised into buckets:
            have unique name and Geographical location
            We can use regional or multi-regional
            Objects created by google are immutable
            A new version is created every change made
            Objecct versioning feature
            History of modifications
        Iam for bucket object:
            For most purposes, Cloud IAM is sufficient ( Inherited from project to bocket to object )
            If we need finer control, we can create access control lists ( ACLs ), ( scope + permission )
        Lifecycle policies:
            features: 
                Unlimited storage ( no min object size )
                Worldwide accessibility and locations
                Low latency and HA
                A uniform experience
                Geo-redundancy
                Always encrypts data on the server side
                use https/tls
            Standard:
                Hot data ( frequently access )
            Nearline :
                once per month
            Coldline:
                once every 90 days
            Archive:
                once a year
            Autoclass:
        Storing data:
            Online transfer:
                using gcloud sdk, UI ( drag and drop )
            Storage transfer service:
                for a huge amount of data
            Transfer appliance:
    Cloud SQL:
        Relational databases:
            Mysql
            Postgresql
            Sql server
            Mundane tasks: 
                Applying patches
                Managing backups
                Configuring replications
        Features:
            Doesn't require any software installation or maintenance
            Can scale upto 64 processor cores, 400+ gb ram, 30tb of storage
            Supports automatic replication scenarios
            Suports managed backups - The cost of an isntance covers 7 backups
            Encrypts customer data when on Google's internal networks and when stored in databases tables, temporary files, and backups
            Includes a network firewall
            Instances of cloud SQL are accessible by other Google Cloud ad external services
    Cloud Spanner:
        Fully managed relational database service:
            Scales horizontally
            Strongly consistent
            Speaks SQL  
        Sutaible for application that require:
            SQL relational database management system with joins and secondary indexes
            Built-in HA
            Strong global consistency
            High numbers of ip/op operations per sec
    Firestore:
        Features:
            Flexible
            Horizontally scalable
            NoSql cloud database
            Retrive individual documents
            Retrieve all the documents in a collection
            Can include multile, chained filters
            Can combine filtering and sorting options
            Indexed by default
            Use synchronization to update data at any connected device
            Automatic multi-region data replicationStrong consistency guranteees
            Atomic batch operations
            Real transations support
            When using Firestore, you are charged for:
                Reading, writing and deleting documents
                Queries, which are counted as one documet read
                The amount of database storage used
                THe amount of network bandwidth used*
            Firestore has a free quota per day of:
                50,000 documents read
                20,000 documents write
                20,000 documents deletes
                1GB of stored data
        Incoming data -> Documents -> Collections
    Cloud Bigtable:
        Google's NoSQL bigdata database service which powers core services like search, analytics, maps and gmail
        Used to handle massive workloads 
        Consistent low latency 
        High throughput      
        Great choice for:
            Operational applicatons
            Analytical applications
        Customer often choose BIgtable if:
            They work with more than 1tb of semi-structured or structured data
            Data id fast with high throughput, or it's ralidly changing
            They work with Nosql data
            Data is a time-series or has neutral semantic ordering
            They work with big data, running asynchronous batch or synchronous real-time processing on the data
            They run machine learing algorithms on the data
    Comparing storage options:
    Big Query:
        On the edge btw data storage and data processing
Week-6:
Containers in the cloud:
    conatiners:
    Kubernetes:
    Kubernetes engine:
week-7:
Applications in the cloud:
    Cloud run:
        A managed compute platform that can run stateless containers
        Serverless, removing the need for infrastructure management
        Built on knative, an open API and runtime built on kubernetes
        Can automatically scale up and odwn from zero almost instantaneously, charging only for the resources used
        steps:
            1. write your code
            2. Build and package (container image)
            3. push to artifact regisry
            4. Deploy to cloud run 
        It will provide the https url back, cloud run then starts your container on demand to handle requests, and ensures that all incoming requests are handled by dynamically adding and removing containers:
            (source code > ) write code, ( container image (using buildpacks ) > web app ) deploy to cloud run
        With cloud run you can use a container-based workflow as well as a source-based workflow
        Only have to pay while container is handling requests, startup and shutdown
    Development in the cloud:

    Cloud Functions:
        Lightweight, event-based, asynchronous compute solution
        Allows you to create small, single-purpose fucntions that respond to cloud events without he need to manage a server or a runtime environment
        Construct application workflows from individual bussiness logic tasks and connect and extend cloud services
        Billed to the nearest 100 ms , and only while your code is running 
        Suports code in node, pyhton, go, java, .Net Core, Ruby, and PHP
        Events from cloud storage and Pub/Sub can trigger Cloud functions asynchronously, or use http invocation for synchronous execution