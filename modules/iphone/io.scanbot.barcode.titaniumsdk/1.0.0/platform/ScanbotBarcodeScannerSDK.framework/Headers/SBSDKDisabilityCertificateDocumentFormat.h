//
//  SBSDKDisabilityCertificateDocumentFormat.h
//  ScanbotSDKBeta
//
//  Created by Andrew Petrus on 20.05.19.
//  Copyright © 2019 doo GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SBSDKBarCodeScannerDocumentFormat.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * DC document field types.
 */
typedef NS_ENUM(NSInteger, SBSDKDisabilityCertificateDocumentFieldType) {
    /** Requires care. */
    SBSDKDisabilityCertificateDocumentFieldTypeRequiresCare,
    /** Accident. */
    SBSDKDisabilityCertificateDocumentFieldTypeAccident,
    /** Initial certificate. */
    SBSDKDisabilityCertificateDocumentFieldTypeInitialCertificate,
    /** Renewed certificate. */
    SBSDKDisabilityCertificateDocumentFieldTypeRenewedCertificate,
    /** Work accident. */
    SBSDKDisabilityCertificateDocumentFieldTypeWorkAccident,
    /** Assigned to accident insurance doctor. */
    SBSDKDisabilityCertificateDocumentFieldTypeAssignedToAccidentInsuranceDoctor,
    /** Incapable of work since. */
    SBSDKDisabilityCertificateDocumentFieldTypeIncapableOfWorkSince,
    /** Incapable of work until. */
    SBSDKDisabilityCertificateDocumentFieldTypeIncapableOfWorkUntil,
    /** Diagnosed on. */
    SBSDKDisabilityCertificateDocumentFieldTypeDiagnosedOn,
    /** Document date. */
    SBSDKDisabilityCertificateDocumentFieldTypeDocumentDate,
    /** Birth date. */
    SBSDKDisabilityCertificateDocumentFieldTypeBirthDate,
    /** First name. */
    SBSDKDisabilityCertificateDocumentFieldTypeFirstName,
    /** Last name. */
    SBSDKDisabilityCertificateDocumentFieldTypeLastName,
    /** Diagnose. */
    SBSDKDisabilityCertificateDocumentFieldTypeDiagnose,
    /** Health insurance number. */
    SBSDKDisabilityCertificateDocumentFieldTypeHealthInsuranceNumber,
    /** Insured person number. */
    SBSDKDisabilityCertificateDocumentFieldTypeInsuredPersonNumber,
    /** Status. */
    SBSDKDisabilityCertificateDocumentFieldTypeStatus,
    /** Place of operation number. */
    SBSDKDisabilityCertificateDocumentFieldTypePlaceOfOperationNumber,
    /** Doctor number. */
    SBSDKDisabilityCertificateDocumentFieldTypeDoctorNumber
};

/**
 * DC field description.
 */
@interface SBSDKDisabilityCertificateDocumentField : NSObject
    
/** Field type. */
@property (nonatomic) SBSDKDisabilityCertificateDocumentFieldType type;

/** Human-readable field type name. */
@property (nonatomic, strong, readonly) NSString *typeHumanReadableString;
    
/** Field value. */
@property (nonatomic, strong) NSString *value;

@end

/**
 * Class for parsing data obtained from QR code on disability certificates.
 */
@interface SBSDKDisabilityCertificateDocumentFormat : SBSDKBarCodeScannerDocumentFormat

/** Document fields. */
@property (nonatomic, strong) NSArray<SBSDKDisabilityCertificateDocumentField *> *fields;

@end

NS_ASSUME_NONNULL_END
